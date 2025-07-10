void __fastcall vostok::tasks::task::unlink_from_child(int a1, vostok::tasks::task *child)
{
  signed __int32 v2; // eax

  do
  {
    while ( 1 )
    {
      v2 = _InterlockedCompareExchange(&child->m_state, 4, 2);
      if ( v2 != 2 )
        break;
      child->m_parent = 0;
      _InterlockedCompareExchange(&child->m_state, 2, 4);
    }
  }
  while ( v2 != 3 );
}
