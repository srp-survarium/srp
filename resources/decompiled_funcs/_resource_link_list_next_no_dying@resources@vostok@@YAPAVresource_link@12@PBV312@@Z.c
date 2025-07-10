vostok::resources::resource_link *__usercall vostok::resources::resource_link_list_next_no_dying@<eax>(
        const vostok::resources::resource_link *object@<eax>)
{
  vostok::resources::resource_link *result; // eax

  for ( result = object->next_link; result; result = result->next_link )
  {
    if ( (result->resource->m_flags.m_flags & 0x800) == 0 )
      break;
  }
  return result;
}
