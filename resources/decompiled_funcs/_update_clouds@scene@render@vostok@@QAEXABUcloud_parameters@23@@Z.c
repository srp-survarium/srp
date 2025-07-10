void __usercall vostok::render::scene::update_clouds(
        vostok::render::scene *this@<ecx>,
        vostok::render::scene *a2@<eax>)
{
  int m_clouds; // esi

  m_clouds = (int)a2->m_clouds;
  if ( m_clouds )
    vostok::render::clouds::initialize(
      (vostok::render::clouds *)this,
      m_clouds,
      (const vostok::render::cloud_parameters *)this);
  else
    vostok::render::scene::add_clouds(this, a2, (vostok::render::clouds *)this);
}
