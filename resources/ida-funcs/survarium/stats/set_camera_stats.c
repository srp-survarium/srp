void __usercall survarium::stats::set_camera_stats(
        survarium::stats *this@<esi>,
        const vostok::math::float3 *pos@<eax>,
        const vostok::math::float3 *dir@<edi>,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34)
{
  char buff1[64]; // [esp+5Ch] [ebp-80h] BYREF
  char vars0; // [esp+DCh] [ebp+0h] BYREF

  vostok::sprintf<64>((char (*)[64])buff1, "camera position: %3.2f %3.2f %3.2f", pos->x, pos->y, pos->z);
  this->m_camera_position->set_text(this->m_camera_position, buff1);
  vostok::sprintf<64>((char (*)[64])&vars0, "camera direction: %3.2f %3.2f %3.2f", dir->x, dir->y, dir->z);
  this->m_camera_direction->set_text(this->m_camera_direction, &vars0);
  vostok::sprintf<64>((char (*)[64])&a34, "crosshair distance: %3.1fm", this->m_crosshair_dist);
  this->m_crosshair_distance->set_text(this->m_crosshair_distance, (const char *)&a34);
}
