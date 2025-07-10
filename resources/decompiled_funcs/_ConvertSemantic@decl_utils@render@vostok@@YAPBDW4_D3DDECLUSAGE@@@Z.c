char *__thiscall vostok::render::decl_utils::ConvertSemantic(_D3DDECLUSAGE Semantic)
{
  int v1; // eax

  v1 = 0;
  while ( vostok::render::decl_utils::VertexSemanticList[v1].m_dx9Semantic != Semantic )
  {
    if ( ++v1 >= 10 )
      return 0;
  }
  return (&off_9BB8AC)[2 * v1];
}
