void __usercall ssl_buf_freelist_free(ssl3_buf_freelist_st *list@<edi>)
{
  ssl3_buf_freelist_entry_st *head; // eax
  ssl3_buf_freelist_entry_st *next; // esi

  head = list->head;
  if ( head )
  {
    do
    {
      next = head->next;
      CRYPTO_free(head);
      head = next;
    }
    while ( next );
  }
  CRYPTO_free(list);
}
