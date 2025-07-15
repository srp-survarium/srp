void __thiscall vostok::sound::sound_spl::sound_spl(vostok::sound::sound_spl *this)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  this->__vftable = (vostok::sound::sound_spl_vtbl *)&vostok::sound::sound_spl::`vftable';
  this->m_curve_line.points.pointer = 0;
  HIDWORD(this->m_curve_line.points.max_storage) = 0;
  this->m_curve_line.num_points = 0;
}
