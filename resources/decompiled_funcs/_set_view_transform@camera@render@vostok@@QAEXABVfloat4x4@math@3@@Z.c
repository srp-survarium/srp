void __usercall vostok::render::camera::set_view_transform(
        vostok::render::camera *this@<edx>,
        const vostok::math::float4x4 *matrix@<eax>)
{
  vostok::math::float4x4 *v2; // eax
  int v3; // edx

  qmemcpy(this, matrix, 0x40u);
  v2 = invert_impl(
         &this->m_view,
         (float)((float)((float)((float)(this->m_view.j.y * this->m_view.k.z)
                               - (float)(this->m_view.j.z * this->m_view.k.y))
                       * this->m_view.i.x)
               - (float)((float)((float)(this->m_view.j.x * this->m_view.k.z)
                               - (float)(this->m_view.k.x * this->m_view.j.z))
                       * this->m_view.i.y))
       + (float)((float)((float)(this->m_view.j.x * this->m_view.k.y) - (float)(this->m_view.k.x * this->m_view.j.y))
               * this->m_view.i.z));
  qmemcpy((void *)(v3 + 64), v2, 0x40u);
}
