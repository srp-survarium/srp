void __usercall vostok::render::skeleton_render_model::update(
        vostok::render::skeleton_render_model *this@<esi>,
        const vostok::render::vector<vostok::math::float4x4> *bones@<edi>)
{
  unsigned __int8 i; // bl
  vostok::render::render_surface *v3; // ecx

  for ( i = 0; i < this->m_childs_count; ++i )
  {
    v3 = this->m_childs[i];
    ((void (__thiscall *)(vostok::render::render_surface *, const vostok::render::vector<vostok::math::float4x4> *))v3->__vftable[1].~vostok::render::render_surface)(
      v3,
      bones);
  }
}
