unsigned int __stdcall Scaleform::Alg::Random::NextRandom()
{
  unsigned int v0; // ecx
  __int64 v1; // rax
  int v2; // esi
  unsigned int result; // eax

  v0 = (LOBYTE(Generator_1.I) + 1) & 7;
  Generator_1.I = v0;
  v1 = Generator_1.C + 716514398LL * Generator_1.Q[v0];
  v2 = HIDWORD(v1) + v1;
  Generator_1.C = HIDWORD(v1);
  if ( (unsigned int)(HIDWORD(v1) + v1) < HIDWORD(v1) )
  {
    ++v2;
    Generator_1.C = HIDWORD(v1) + 1;
  }
  result = -2 - v2;
  Generator_1.Q[v0] = -2 - v2;
  return result;
}
