void __userpurge vostok::sound::sound_spl::load(
        vostok::sound::sound_spl *this@<ecx>,
        float a2@<xmm0>,
        const vostok::configs::binary_config_value *t_root)
{
  vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(&this->m_curve_line, a2, *t_root);
}
