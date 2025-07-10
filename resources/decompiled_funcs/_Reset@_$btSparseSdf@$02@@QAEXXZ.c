void __thiscall btSparseSdf<3>::Reset(btSparseSdf<3> *this, btSparseSdf<3> *thisa)
{
  int m_size; // ebp
  int i; // edi
  btSparseSdf<3>::Cell **v4; // ecx
  btSparseSdf<3>::Cell *v5; // eax
  btSparseSdf<3>::Cell *next; // esi

  m_size = thisa->cells.m_size;
  for ( i = 0; i < m_size; ++i )
  {
    v4 = &thisa->cells.m_data[i];
    v5 = *v4;
    *v4 = 0;
    if ( v5 )
    {
      do
      {
        next = v5->next;
        operator delete(v5);
        v5 = next;
      }
      while ( next );
    }
  }
  thisa->puid = 0;
  thisa->ncells = 0;
  thisa->voxelsz = 0.25;
  thisa->nprobes = 1;
  thisa->nqueries = 1;
}
