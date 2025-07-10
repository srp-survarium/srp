void __userpurge vostok::render::speedtree_billboard_parameters::set_billboard_tangents(
        vostok::render::speedtree_billboard_parameters *this@<ecx>,
        unsigned int a2@<esi>,
        vostok::render::constants_handler<0> **camera_azimuth,
        float camera_azimutha)
{
  const char *m_conflicted_key_name; // esi
  vostok::render::constants_handler<0> *v5; // ecx
  float _X; // [esp+0h] [ebp-78h]
  float v7; // [esp+4h] [ebp-74h]
  __int64 tangent; // [esp+14h] [ebp-64h]
  float tangent_8; // [esp+1Ch] [ebp-5Ch]
  struct SpeedTree::Vec3 binormal; // [esp+20h] [ebp-58h]
  SpeedTree::Vec3 normal; // [esp+2Ch] [ebp-4Ch] BYREF
  unsigned __int64 v13; // [esp+38h] [ebp-40h]
  float v14; // [esp+40h] [ebp-38h]
  vostok::math::float4 billboard_tangents[3]; // [esp+44h] [ebp-34h] BYREF
  float camera_azimuthb; // [esp+80h] [ebp+8h]

  camera_azimuthb = camera_azimutha + 3.1415927;
  if ( (unsigned __int8)SpeedTree::CCoordSys::IsLeftHanded() )
    camera_azimuthb = 3.1415927 - camera_azimuthb;
  binormal = *SpeedTree::CCoordSys::UpAxis();
  v7 = sinf(camera_azimuthb);
  _X = cosf(camera_azimuthb);
  SpeedTree::CCoordSys::ConvertFromStd(&normal, _X, v7, 0.0);
  *(float *)&tangent = (float)(binormal.y * normal.z) - (float)(binormal.z * normal.y);
  *((float *)&tangent + 1) = (float)(binormal.z * normal.x) - (float)(binormal.x * normal.z);
  tangent_8 = (float)(binormal.x * normal.y) - (float)(binormal.y * normal.x);
  if ( (unsigned __int8)SpeedTree::CCoordSys::IsYAxisUp() && !(unsigned __int8)SpeedTree::CCoordSys::IsLeftHanded()
    || !(unsigned __int8)SpeedTree::CCoordSys::IsYAxisUp() && (unsigned __int8)SpeedTree::CCoordSys::IsLeftHanded() )
  {
    v13 = tangent ^ 0x8000000080000000uLL;
    v14 = -tangent_8;
    tangent ^= 0x8000000080000000uLL;
    tangent_8 = -tangent_8;
  }
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *(_QWORD *)&billboard_tangents[1].x = *(_QWORD *)&binormal.x;
  *(_QWORD *)&billboard_tangents[0].x = *(_QWORD *)&normal.x;
  *(_QWORD *)&billboard_tangents[1].elements[2] = LODWORD(binormal.z);
  *(_QWORD *)&billboard_tangents[2].x = tangent;
  *(_QWORD *)&billboard_tangents[0].elements[2] = LODWORD(normal.z);
  v5 = *camera_azimuth;
  *(_QWORD *)&billboard_tangents[2].elements[2] = LODWORD(tangent_8);
  vostok::render::constants_handler<0>::set_constant_array<vostok::math::float4>(
    v5,
    (vostok::render::constants_handler<0> *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                           + 196),
    billboard_tangents,
    a2);
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
