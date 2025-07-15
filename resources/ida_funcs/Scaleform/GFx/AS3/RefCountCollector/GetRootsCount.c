unsigned int __thiscall Scaleform::GFx::AS3::RefCountCollector<328>::GetRootsCount(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        unsigned int uptoGen)
{
  unsigned int v2; // ebp
  int v3; // edi
  int v4; // ebx
  unsigned int v5; // esi
  unsigned int *p_nRoots; // edx

  v2 = 0;
  v3 = 0;
  v4 = 0;
  if ( (int)(uptoGen + 1) < 2 )
    return v3 + v4 + this->Roots[v2].nRoots;
  v5 = (uptoGen + 1) >> 1;
  p_nRoots = &this->Roots[1].nRoots;
  v2 = 2 * v5;
  do
  {
    v3 += *(p_nRoots - 2);
    v4 += *p_nRoots;
    p_nRoots += 4;
    --v5;
  }
  while ( v5 );
  if ( v2 > uptoGen )
    return v3 + v4;
  else
    return v3 + v4 + this->Roots[v2].nRoots;
}
