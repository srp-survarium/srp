void __thiscall vostok::ai::sensors::update_visibility_predicate::operator()(
        vostok::ai::sensors::update_visibility_predicate *this,
        vostok::ai::sensed_visual_object *visual_object)
{
  vostok::math::float4x4 *v2; // eax
  vostok::math::float3 *p_npc_position; // esi
  const vostok::math::float3 *v4; // eax
  vostok::math::float3 *v5; // eax
  vostok::math::float3 *v6; // eax
  vostok::math::float3_pod *v7; // ecx
  vostok::math::float3 *v8; // ecx
  survarium::game_camera *z_low; // ecx
  _BYTE *v10; // eax
  vostok::ai::sensors::update_visibility_parameters *parameters; // esi
  double v12; // st7
  vostok::ai::sensors::update_visibility_parameters *v13; // esi
  float v14; // [esp+14h] [ebp-D0h]
  float visibility_threshold; // [esp+18h] [ebp-CCh]
  float v16; // [esp+20h] [ebp-C4h]
  float v17; // [esp+2Ch] [ebp-B8h]
  float v19; // [esp+34h] [ebp-B0h]
  vostok::math::float3 v20; // [esp+48h] [ebp-9Ch] BYREF
  _BYTE v21[12]; // [esp+54h] [ebp-90h] BYREF
  vostok::math::float3 v22; // [esp+60h] [ebp-84h] BYREF
  _BYTE v23[67]; // [esp+78h] [ebp-6Ch] BYREF
  bool ray_query_succeeded; // [esp+BBh] [ebp-29h]
  float visibility_delta; // [esp+BCh] [ebp-28h]
  float visibility_value; // [esp+C0h] [ebp-24h]
  const vostok::ai::npc *npc_object; // [esp+C4h] [ebp-20h]
  const vostok::math::float3 *point_in_world_frame; // [esp+C8h] [ebp-1Ch]
  vostok::math::float3 v29; // [esp+CCh] [ebp-18h] BYREF
  unsigned int time_delta; // [esp+D8h] [ebp-Ch]
  float calculated_luminosity; // [esp+DCh] [ebp-8h]
  const vostok::math::float4x4 *ray_energy; // [esp+E0h] [ebp-4h]

  ray_energy = clear_value;
  v2 = visual_object->object->local_to_cell(visual_object->object, v23, &this->parameters->npc_position);
  vostok::math::float4x4::transform_position(&visual_object->local_point, &v29, v2);
  point_in_world_frame = &v29;
  ray_query_succeeded = 0;
  if ( this->parameters->object_to_ignore->debug_draw_allowed(this->parameters->object_to_ignore) )
    vostok::ai::ai_world::draw_ray(this->world, &this->parameters->npc_position, point_in_world_frame, 0);
  npc_object = visual_object->object->cast_npc(visual_object->object);
  time_delta = (vostok::ai::ai_world::get_current_time_in_ms(this->world) - this->parameters->last_update_time) / 0x3E8;
  p_npc_position = &this->parameters->npc_position;
  vostok::math::float3::float3(&v22, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  v5 = npc_object->get_position(npc_object, v21, v4);
  v6 = vostok::math::operator-(p_npc_position, v5, &v20);
  v17 = vostok::math::float3_pod::length(v7, &v6->x);
  visual_object->distance = v17;
  v8 = &this->parameters->npc_position;
  *(_QWORD *)&visual_object->own_position.x = *(_QWORD *)&v8->x;
  z_low = (survarium::game_camera *)LODWORD(v8->z);
  LODWORD(visual_object->own_position.z) = z_low;
  visual_object->was_visible_last_time = 0;
  survarium::weapon_user_dead_state::finalize(z_low);
  if ( *v10 )
  {
    parameters = this->parameters;
    v19 = ((double (__thiscall *)(const vostok::ai::game_object *))visual_object->object->get_luminosity)(visual_object->object)
        * parameters->luminosity_factor;
    v12 = expf(v14);
    calculated_luminosity = v19;
    v13 = this->parameters;
    v16 = (double)time_delta / v13->time_quant * v19;
    visual_object->object->get_velocity((vostok::ai::game_object *)visual_object->object);
    visibility_delta = (v12 * v13->velocity_factor + 1.0)
                     * v16
                     * (this->parameters->far_plane_distance - visual_object->distance)
                     / (this->parameters->far_plane_distance - this->parameters->near_plane_distance);
    visibility_value = (float)(visibility_delta * *(float *)&ray_energy) + visual_object->visibility_value;
    if ( visibility_value > this->parameters->max_visibility_value )
      visibility_value = this->parameters->max_visibility_value;
    visual_object->was_updated = visual_object->visibility_value != visibility_value;
    if ( visual_object->newly_added_to_frustum )
      visibility_threshold = this->parameters->visibility_threshold;
    else
      visibility_threshold = visibility_value;
    visual_object->visibility_value = visibility_threshold;
    visual_object->newly_added_to_frustum = 0;
  }
  else
  {
    visual_object->visibility_value = visual_object->visibility_value - this->parameters->decrease_factor;
  }
}
