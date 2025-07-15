int __cdecl Scaleform::Render::MeshKey::GetKeySize(char flags)
{
  int v1; // eax

  v1 = 3;
  if ( (flags & 0x10) != 0 )
    v1 = 13;
  return v1 + 1;
}
