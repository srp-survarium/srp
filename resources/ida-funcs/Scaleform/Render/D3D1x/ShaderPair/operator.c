BOOL __usercall Scaleform::Render::D3D1x::ShaderPair::operator bool@<eax>(
        Scaleform::Render::D3D1x::ShaderPair *this@<ecx>,
        _DWORD *a2@<eax>)
{
  int v2; // ecx
  BOOL result; // eax

  result = 0;
  if ( *a2 )
  {
    v2 = a2[2];
    if ( v2 )
    {
      if ( *(_DWORD *)(*a2 + 4) && *(_DWORD *)(v2 + 4) && a2[4] )
        return 1;
    }
  }
  return result;
}
