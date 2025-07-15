void (__cdecl *pushsig())(int)
{
  void (__cdecl *result)(int); // eax

  savsig[22] = (void (__cdecl *)(int))signal(22, recsig);
  savsig[8] = (void (__cdecl *)(int))signal(8, recsig);
  savsig[4] = (void (__cdecl *)(int))signal(4, recsig);
  savsig[2] = (void (__cdecl *)(int))signal(2, recsig);
  savsig[11] = (void (__cdecl *)(int))signal(11, recsig);
  result = (void (__cdecl *)(int))signal(15, recsig);
  savsig[15] = result;
  return result;
}
