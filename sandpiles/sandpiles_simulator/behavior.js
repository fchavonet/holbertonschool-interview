/**
 * Initializes the sandpile grids and the result grid once the DOM is fully loaded.
 */
document.addEventListener("DOMContentLoaded", function () {
    createGrid("grid_1", 2);
    createGrid("grid_2", 1);
    createEmptyResultGrid();
});

/**
 * Creates a 3x3 grid in the specified table and initializes each cell with the given default value.
 * 
 * @param {string} gridId - The ID of the HTML table where the grid will be created.
 * @param {number} defaultValue - The default value to populate in each input cell.
 */
function createGrid(gridId, defaultValue) {
    let table = document.getElementById(gridId);

    for (let i = 0; i < 3; i++) {
        let row = document.createElement("tr");

        for (let j = 0; j < 3; j++) {
            let cell = document.createElement("td");
            let input = document.createElement("input");

            input.type = "text";
            input.value = defaultValue;

            // Restrict the input to a single digit.
            input.addEventListener("input", function () {
                // Remove any non-digit characters.
                input.value = input.value.replace(/[^0-9]/g, "");
                // Limit input to the first character (one digit).
                input.value = input.value.slice(0, 1);
            });

            cell.appendChild(input);
            row.appendChild(cell);
        }
        table.appendChild(row);
    }
}

/**
 * Creates an empty 3x3 result grid filled with space characters in the cells.
 * This grid will be used to display the stabilized sandpile result.
 */
function createEmptyResultGrid() {
    let resultTable = document.getElementById("result");

    for (let i = 0; i < 3; i++) {
        let row = document.createElement("tr");

        for (let j = 0; j < 3; j++) {
            let cell = document.createElement("td");

            cell.textContent = "_";

            row.appendChild(cell);
        }
        resultTable.appendChild(row);
    }
}

/**
 * Computes the sandpile result by summing the values of grid_1 and grid_2. 
 * Then stabilizing the result through repeated toppling operations.
 */
function computeSandpile() {
    // Disable the compute button.
    document.getElementById("computeButton").disabled = true;

    let grid1 = getGridValues("grid_1");
    let grid2 = getGridValues("grid_2");
    let resultGrid = sandpilesSum(grid1, grid2);

    stabilizeGrid(resultGrid);
}

/**
 * Retrieves the numerical values from a grid and returns them as a 2D array.
 * 
 * @param {string} gridId - The ID of the grid table from which to extract values.
 * @returns {number[][]} - A 2D array of the grid values.
 */
function getGridValues(gridId) {
    let table = document.getElementById(gridId);
    let values = [];

    for (let i = 0; i < 3; i++) {
        let row = [];

        for (let j = 0; j < 3; j++) {
            let input = table.rows[i].cells[j].querySelector("input").value;
            // Convert the value to an integer or default to 0.
            row.push(parseInt(input) || 0);
        }
        values.push(row);
    }
    return values;
}

/**
 * Adds the corresponding values of two grids and returns the resulting grid.
 * 
 * @param {number[][]} grid1 - The first grid to sum.
 * @param {number[][]} grid2 - The second grid to sum.
 * @returns {number[][]} - The resulting grid after summing grid1 and grid2.
 */
function sandpilesSum(grid1, grid2) {
    let resultGrid = [];

    for (let i = 0; i < 3; i++) {
        let row = [];

        for (let j = 0; j < 3; j++) {
            row.push(grid1[i][j] + grid2[i][j]);
        }
        resultGrid.push(row);
    }
    displayResult(resultGrid);

    return resultGrid;
}

/**
 * Checks if the grid is stable, meaning all values are less than or equal to 3.
 * 
 * @param {number[][]} grid - The grid to check for stability.
 * @returns {boolean} - True if the grid is stable, false otherwise.
 */
function isStable(grid) {
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {

            if (grid[i][j] > 3) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Performs one round of toppling on the grid, redistributing values greater than 3 to their neighboring cells.
 * 
 * @param {number[][]} grid - The grid to topple.
 * @returns {number[][]} - The grid after one toppling round.
 */
function topplingRound(grid) {
    // Deep copy the grid.
    let newGrid = JSON.parse(JSON.stringify(grid));

    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {

            if (grid[i][j] > 3) {
                newGrid[i][j] -= 4;

                //  Top neighbor.
                if (i - 1 >= 0) newGrid[i - 1][j] += 1;
                // Right neighbor.
                if (j + 1 < 3) newGrid[i][j + 1] += 1;
                // Bottom neighbor.
                if (i + 1 < 3) newGrid[i + 1][j] += 1;
                // Left neighbor.
                if (j - 1 >= 0) newGrid[i][j - 1] += 1;
            }
        }
    }
    return newGrid;
}

/**
 * Continuously stabilizes the grid by applying toppling rounds until no cell has a value greater than 3.
 * 
 * @param {number[][]} grid - The grid to stabilize.
 */
function stabilizeGrid(grid) {
    if (!isStable(grid)) {
        setTimeout(function () {
            // Perform one round of toppling.
            grid = topplingRound(grid);
            // Display the updated grid.
            displayResult(grid);
            // Recursively stabilize the grid.
            stabilizeGrid(grid);
        }, 1500); // Set a 1-second delay between toppling rounds.
    } else {
        // Re-enable the compute button.
        document.getElementById("computeButton").disabled = false;
    }
}

/**
 * Displays the grid values in the result table.
 * 
 * @param {number[][]} grid - The grid to display.
 */
function displayResult(grid) {
    let resultTable = document.getElementById("result");

    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            resultTable.rows[i].cells[j].textContent = grid[i][j];
        }
    }
}
