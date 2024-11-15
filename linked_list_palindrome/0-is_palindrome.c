#include "lists.h"

/**
 * reverse_list - Reverses a linked list.
 * @head: pointer to the head of the list to reverse.
 *
 * Return: pointer to the head of the reversed list.
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *next = NULL;

	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: double pointer to the head of the list.
 *
 * Return: 1 if it is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	if (!head || !*head || !(*head)->next)
		return (1);

	listint_t *slow = *head, *fast = *head, *second_half, *first_half = *head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	second_half = reverse_list(slow);
	listint_t *copy_second_half = second_half;

	while (second_half)
	{
		if (first_half->n != second_half->n)
		{
			reverse_list(copy_second_half);
			return (0);
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}

	reverse_list(copy_second_half);
	return (1);
}
