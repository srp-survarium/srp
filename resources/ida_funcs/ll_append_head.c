void __fastcall ll_append_head(cipher_order_st **tail, cipher_order_st **head, cipher_order_st *curr)
{
  cipher_order_st *next; // ecx
  cipher_order_st *prev; // ecx

  if ( curr != *head )
  {
    if ( curr == *tail )
      *tail = curr->prev;
    next = curr->next;
    if ( next )
      next->prev = curr->prev;
    prev = curr->prev;
    if ( prev )
      prev->next = curr->next;
    (*head)->prev = curr;
    curr->next = *head;
    curr->prev = 0;
    *head = curr;
  }
}
