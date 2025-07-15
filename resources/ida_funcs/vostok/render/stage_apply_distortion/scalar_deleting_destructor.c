vostok::render::stage_apply_distortion *__thiscall vostok::render::stage_apply_distortion::`scalar deleting destructor'(
        vostok::render::stage_apply_distortion *this,
        char a2)
{
  vostok::render::res_effect *m_object; // eax

  this->__vftable = (vostok::render::stage_apply_distortion_vtbl *)&stru_965008.m_sh_res_view;
  m_object = this->m_sh_apply_distortion.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_sh_apply_distortion.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_sh_apply_distortion.m_object);
  this->__vftable = (vostok::render::stage_apply_distortion_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
