void __thiscall vostok::sound::sound_spl::~sound_spl(vostok::sound::sound_spl *this)
{
  this->__vftable = (vostok::sound::sound_spl_vtbl *)&vostok::sound::sound_spl::`vftable';
  vostok::math::curve_line_points<float,0>::~curve_line_points<float,0>(&this->m_curve_line);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
