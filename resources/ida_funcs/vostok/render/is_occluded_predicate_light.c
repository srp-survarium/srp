BOOL __cdecl vostok::render::is_occluded_predicate_light(
        const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *obj)
{
  return *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
         + 288)
      && obj->m_object->m_occluded;
}
