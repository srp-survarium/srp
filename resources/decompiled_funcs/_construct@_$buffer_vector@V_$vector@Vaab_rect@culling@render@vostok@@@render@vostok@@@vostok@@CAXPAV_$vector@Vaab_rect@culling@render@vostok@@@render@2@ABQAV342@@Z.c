void __usercall vostok::buffer_vector<vostok::render::vector<vostok::render::culling::aab_rect>>::construct(
        vostok::render::vector<vostok::math::frustum> *begin@<edx>,
        vostok::render::vector<vostok::math::frustum> *const *end@<edi>)
{
  vostok::render::vector<vostok::math::frustum> *v2; // ecx
  vostok::render::vector<vostok::math::frustum> *i; // eax

  if ( begin != *end )
  {
    v2 = begin + 1;
    do
    {
      for ( i = begin; i != v2; ++i )
      {
        if ( i )
        {
          i->_M_impl._M_start = 0;
          i->_M_impl._M_finish = 0;
          i->_M_impl._M_end_of_storage._M_data = 0;
        }
      }
      ++begin;
      ++v2;
    }
    while ( begin != *end );
  }
}
