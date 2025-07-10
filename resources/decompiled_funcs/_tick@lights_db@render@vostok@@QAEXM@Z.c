void __userpurge vostok::render::lights_db::tick(
        vostok::render::lights_db *this@<ecx>,
        const float **a2@<eax>,
        float time_delta)
{
  const float *v3; // esi
  const float *v4; // edi

  v3 = *a2;
  v4 = a2[1];
  if ( *a2 != v4 )
  {
    do
    {
      vostok::render::light::tick_color_animation((vostok::render::light *)this, *v3, time_delta);
      v3 += 2;
    }
    while ( v3 != v4 );
  }
}
