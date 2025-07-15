void __usercall vostok::render::renderer::sort_models_by_distance(vostok::render::renderer *this@<ecx>, int a2@<eax>)
{
  int v2; // eax
  vostok::render::sort_by_distance_predicate pos; // [esp+Ch] [ebp-14h]

  v2 = *(_DWORD *)(a2 + 352);
  *(_QWORD *)&pos.m_eye_position.x = *(_QWORD *)(v2 + 16900);
  pos.m_eye_position.z = *(float *)(v2 + 16908);
  pos.m_eye_position.x = (float)(int)vostok::math::floor(pos.m_eye_position.x);
  pos.m_eye_position.y = (float)(int)vostok::math::floor(pos.m_eye_position.y);
  pos.m_eye_position.z = (float)(int)vostok::math::floor(pos.m_eye_position.z);
  pos.m_from_near_to_far = 0;
  stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_distance_predicate>(
    *(vostok::render::render_surface_instance ***)&this->m_picking_lighting_luminance_mode,
    (vostok::render::render_surface_instance **)LODWORD(this->m_view_to_rain_shadow.i.x),
    pos);
}
