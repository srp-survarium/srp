void (__cdecl *__usercall popsig@<eax>(int a1@<edi>))(int)
{
  signal(a1, 22, (_XCPT_ACTION **)savsig[22]);
  signal(a1, 8, (_XCPT_ACTION **)savsig[8]);
  signal(a1, 4, (_XCPT_ACTION **)savsig[4]);
  signal(a1, 2, (_XCPT_ACTION **)savsig[2]);
  signal(a1, 11, (_XCPT_ACTION **)savsig[11]);
  return (void (__cdecl *)(int))signal(a1, 15, (_XCPT_ACTION **)savsig[15]);
}
