unsigned int __cdecl vostok::ai::path_constructor::base::impl<vostok::sound::search::search_service::vertex_type>::length(
        const vostok::sound::search::search_service::vertex_type *vertex)
{
  vostok::sound::search::search_service::vertex_type *j; // [esp+4h] [ebp-8h]
  unsigned int result; // [esp+8h] [ebp-4h]

  result = 1;
  for ( j = vertex->m_back; j; j = j->m_back )
    ++result;
  return result;
}
