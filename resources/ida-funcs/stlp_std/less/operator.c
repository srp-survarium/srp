BOOL __userpurge stlp_std::less<survarium::particle_game_effect_presenter::effect_data>::operator()@<eax>(
        const vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *__x@<eax>,
        stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *this,
        const vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *__y)
{
  vostok::physics::loose_ptr_base *m_pointer; // eax
  vostok::physics::loose_ptr_base *v4; // ecx
  int v5; // eax
  unsigned int v6; // eax

  m_pointer = __x->m_object->m_pointer;
  if ( m_pointer )
    v4 = m_pointer - 1;
  else
    v4 = 0;
  v5 = **(_DWORD **)&this->gap0;
  if ( v5 )
    v6 = v5 - 4;
  else
    v6 = 0;
  return (unsigned int)v4 < v6;
}


bool __usercall stlp_std::less<vostok::render::patch_sample>::operator()@<al>(
        const vostok::render::patch_sample *__x@<ecx>,
        const vostok::render::patch_sample *__y@<eax>)
{
  int x; // edx
  int v4; // esi

  if ( __x->template_id < __y->template_id )
    return 1;
  if ( __x->template_id > __y->template_id )
    return 0;
  x = __x->x;
  v4 = __y->x;
  if ( x < v4 )
    return 1;
  return x <= v4 && __x->y < __y->y;
}


BOOL __usercall stlp_std::less<vostok::memory::platform::region>::operator()@<eax>(
        const vostok::memory::platform::region *__x@<ecx>,
        const vostok::memory::platform::region *__y@<eax>,
        stlp_std::less<vostok::memory::platform::region> *this)
{
  return __x->size < __y->size;
}


BOOL __usercall stlp_std::less<vostok::render::resource_manager::shader_name_config_pair>::operator()@<eax>(
        const vostok::render::resource_manager::shader_name_config_pair *__x@<edi>,
        const vostok::render::resource_manager::shader_name_config_pair *__y@<esi>,
        stlp_std::less<vostok::render::resource_manager::shader_name_config_pair> *this)
{
  int v3; // eax

  v3 = strcmp(__x->name, __y->name);
  return v3 < 0 || !v3 && vostok::render::union_base::operator<(&__x->config, &__y->config);
}


bool __usercall stlp_std::less<vostok::render::texture_pool_key>::operator()@<al>(
        const vostok::render::texture_pool_key *__x@<ecx>,
        const vostok::render::texture_pool_key *__y@<eax>)
{
  unsigned int array_size; // edx
  unsigned int v3; // esi
  bool result; // al
  unsigned int height; // edx
  unsigned int v6; // esi
  DXGI_FORMAT format; // edx
  DXGI_FORMAT v8; // esi
  unsigned int mips; // edx
  unsigned int v10; // esi

  array_size = __x->array_size;
  v3 = __y->array_size;
  result = 1;
  if ( array_size >= v3 )
  {
    if ( array_size > v3 )
      return 0;
    if ( __x->width <= __y->width )
    {
      if ( __x->width < __y->width )
        return 0;
      height = __x->height;
      v6 = __y->height;
      if ( height <= v6 )
      {
        if ( height < v6 )
          return 0;
        format = __x->format;
        v8 = __y->format;
        if ( format <= v8 )
        {
          if ( format < v8 )
            return 0;
          mips = __x->mips;
          v10 = __y->mips;
          if ( mips <= v10 && (mips < v10 || __x->usage <= __y->usage) )
            return 0;
        }
      }
    }
  }
  return result;
}
