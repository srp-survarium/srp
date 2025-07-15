void (__cdecl *__usercall pushsig@<eax>(int a1@<edi>))(int)
{
  void (__cdecl *result)(int); // eax

  savsig[22] = (void (__cdecl *)(int))signal(a1, 22, (_XCPT_ACTION **)recsig);
  savsig[8] = (void (__cdecl *)(int))signal(a1, 8, (_XCPT_ACTION **)recsig);
  savsig[4] = (void (__cdecl *)(int))signal(a1, 4, (_XCPT_ACTION **)recsig);
  savsig[2] = (void (__cdecl *)(int))signal(a1, 2, (_XCPT_ACTION **)recsig);
  savsig[11] = (void (__cdecl *)(int))signal(a1, 11, (_XCPT_ACTION **)recsig);
  result = (void (__cdecl *)(int))signal(a1, 15, (_XCPT_ACTION **)recsig);
  savsig[15] = result;
  return result;
}
