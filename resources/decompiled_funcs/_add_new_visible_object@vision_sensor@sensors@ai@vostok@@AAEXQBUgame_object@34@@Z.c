void __userpurge vostok::ai::sensors::vision_sensor::add_new_visible_object(
        vostok::ai::sensors::vision_sensor *this@<ecx>,
        float a2@<xmm0>,
        const vostok::ai::game_object *const ai_game_object)
{
  vostok::memory::doug_lea_allocator *v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-98h]
  int *_Where; // [esp+88h] [ebp-10h]
  vostok::ai::sensed_visual_object *v8; // [esp+90h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v3, 0x2Cu);
  v8 = (vostok::ai::sensed_visual_object *)operator new(0x2Cu, _Where);
  if ( v8 )
  {
    vostok::ai::sensed_visual_object::sensed_visual_object(v8, a2);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  *(_DWORD *)(v5 + 24) = ai_game_object;
  *(_BYTE *)(v5 + 41) = 1;
  *(_BYTE *)(v5 + 42) = 1;
  vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &this->m_visible_objects,
    (survarium::game_camera *)v5,
    0);
}
