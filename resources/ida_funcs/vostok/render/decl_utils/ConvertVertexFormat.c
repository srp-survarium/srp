int __thiscall vostok::render::decl_utils::ConvertVertexFormat(_D3DDECLTYPE dx9FMT)
{
  int v1; // eax

  v1 = 0;
  while ( vostok::render::decl_utils::VertexFormatList[v1].m_dx9FMT != dx9FMT )
  {
    if ( ++v1 >= 15 )
      return 0;
  }
  return dword_9BB834[2 * v1];
}
