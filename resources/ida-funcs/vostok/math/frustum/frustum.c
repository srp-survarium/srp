void __fastcall vostok::math::frustum::frustum(
        int a1,
        const vostok::math::plane (*planes)[6],
        vostok::math::frustum *this)
{
  vostok::math::frustum *v4; // eax
  vostok::math::frustum *v5; // ecx
  int v6; // ecx

  v4 = this + 1;
  v5 = this;
  if ( v5 != v4 )
  {
    do
    {
      v5->m_planes[0].plane.normal.x = (*planes)[0].normal.x;
      v5->m_planes[0].plane.normal.y = (*planes)[0].normal.y;
      v5->m_planes[0].plane.normal.z = (*planes)[0].normal.z;
      v5->m_planes[0].plane.d = (*planes)[0].d;
      vostok::math::aabb_plane::normalize(v5->m_planes);
      planes = (const vostok::math::plane (*)[6])((char *)planes + 16);
      v5 = (vostok::math::frustum *)(v6 + 20);
    }
    while ( v5 != &this[1] );
  }
}


void __usercall vostok::math::frustum::frustum(
        vostok::math::frustum *this@<esi>,
        const vostok::math::float4x4 *view_multiplied_by_projection@<eax>)
{
  vostok::math::frustum *v2; // ecx
  int v3; // ecx

  this->m_planes[0].plane.normal.x = view_multiplied_by_projection->i.w + view_multiplied_by_projection->i.x;
  this->m_planes[0].plane.normal.y = view_multiplied_by_projection->j.w + view_multiplied_by_projection->j.x;
  this->m_planes[0].plane.normal.z = view_multiplied_by_projection->k.w + view_multiplied_by_projection->k.x;
  this->m_planes[0].plane.d = view_multiplied_by_projection->c.x + view_multiplied_by_projection->c.w;
  this->m_planes[1].plane.normal.x = view_multiplied_by_projection->i.w - view_multiplied_by_projection->i.x;
  this->m_planes[1].plane.normal.y = view_multiplied_by_projection->j.w - view_multiplied_by_projection->j.x;
  this->m_planes[1].plane.normal.z = view_multiplied_by_projection->k.w - view_multiplied_by_projection->k.x;
  this->m_planes[1].plane.d = view_multiplied_by_projection->c.w - view_multiplied_by_projection->c.x;
  this->m_planes[2].plane.normal.x = view_multiplied_by_projection->i.w - view_multiplied_by_projection->i.y;
  this->m_planes[2].plane.normal.y = view_multiplied_by_projection->j.w - view_multiplied_by_projection->j.y;
  this->m_planes[2].plane.normal.z = view_multiplied_by_projection->k.w - view_multiplied_by_projection->k.y;
  this->m_planes[2].plane.d = view_multiplied_by_projection->c.w - view_multiplied_by_projection->c.y;
  this->m_planes[3].plane.normal.x = view_multiplied_by_projection->i.w + view_multiplied_by_projection->i.y;
  this->m_planes[3].plane.normal.y = view_multiplied_by_projection->j.w + view_multiplied_by_projection->j.y;
  this->m_planes[3].plane.normal.z = view_multiplied_by_projection->k.w + view_multiplied_by_projection->k.y;
  this->m_planes[3].plane.d = view_multiplied_by_projection->c.y + view_multiplied_by_projection->c.w;
  this->m_planes[4].plane.normal.x = view_multiplied_by_projection->i.w - view_multiplied_by_projection->i.z;
  this->m_planes[4].plane.normal.y = view_multiplied_by_projection->j.w - view_multiplied_by_projection->j.z;
  this->m_planes[4].plane.normal.z = view_multiplied_by_projection->k.w - view_multiplied_by_projection->k.z;
  this->m_planes[4].plane.d = view_multiplied_by_projection->c.w - view_multiplied_by_projection->c.z;
  this->m_planes[5].plane.normal.x = view_multiplied_by_projection->i.z;
  this->m_planes[5].plane.normal.y = view_multiplied_by_projection->j.z;
  v2 = this;
  this->m_planes[5].plane.normal.z = view_multiplied_by_projection->k.z;
  this->m_planes[5].plane.d = view_multiplied_by_projection->c.z;
  do
  {
    vostok::math::aabb_plane::normalize(v2->m_planes);
    v2 = (vostok::math::frustum *)(v3 + 20);
  }
  while ( v2 != &this[1] );
}
