void __thiscall vostok::ai::sensors::vision_sensor::trace_objects_in_frustum(vostok::ai::sensors::vision_sensor *this)
{
  unsigned int current_time_in_ms; // eax
  vostok::math::float3 *v2; // eax
  _BYTE v4[12]; // [esp+4h] [ebp-10h] BYREF
  vostok::ai::sensed_visual_object *it_object; // [esp+10h] [ebp-4h]

  for ( it_object = this->m_visible_objects.m_first; it_object; it_object = it_object->next )
  {
    if ( !it_object->was_visible_last_time )
    {
      current_time_in_ms = vostok::ai::ai_world::get_current_time_in_ms(this->m_world);
      v2 = it_object->object->get_random_surface_point(it_object->object, v4, current_time_in_ms);
      it_object->local_point = *v2;
    }
  }
}
