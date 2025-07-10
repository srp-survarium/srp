void __thiscall vostok::resources::association_callback_helper::get_query(
        vostok::resources::association_callback_helper *this,
        vostok::vfs::vfs_association **association)
{
  vostok::resources::query_result *v2; // eax

  v2 = (vostok::resources::query_result *)*association;
  if ( *association )
  {
    if ( v2->type == 2 )
      this->query = v2;
  }
}
