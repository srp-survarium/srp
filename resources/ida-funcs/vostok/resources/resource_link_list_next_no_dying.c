vostok::resources::resource_link *__usercall vostok::resources::resource_link_list_next_no_dying@<eax>(
        vostok::resources::resource_link *object@<eax>)
{
  do
    object = object->next_link;
  while ( object && (object->resource->m_flags.m_flags & 0x800) != 0 );
  return object;
}
