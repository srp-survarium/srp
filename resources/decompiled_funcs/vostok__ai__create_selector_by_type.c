vostok::ai::selectors::target_selector_base *__cdecl vostok::ai::create_selector_by_type(
        vostok::ai::ai_world *world,
        const char *selector_type,
        const vostok::ai::working_memory *memory,
        vostok::ai::blackboard *board,
        vostok::ai::brain_unit *brain)
{
  survarium::game_camera *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // eax
  int v7; // eax
  survarium::game_camera *v9; // ecx
  vostok::memory::doug_lea_allocator *v10; // eax
  int v11; // eax
  bool v12; // al
  vostok::memory::doug_lea_allocator *v13; // eax
  int v14; // eax
  survarium::game_camera *v15; // ecx
  vostok::memory::doug_lea_allocator *v16; // eax
  int v17; // eax
  survarium::game_camera *v18; // ecx
  vostok::memory::doug_lea_allocator *v19; // eax
  int v20; // eax
  bool v21; // al
  vostok::memory::doug_lea_allocator *v22; // eax
  int v23; // eax
  bool v24; // al
  vostok::memory::doug_lea_allocator *v25; // eax
  int v26; // eax
  bool v27; // al
  vostok::memory::doug_lea_allocator *v28; // eax
  int v29; // eax
  int *v38; // [esp+20h] [ebp-6Ch]
  int *v39; // [esp+2Ch] [ebp-60h]
  int *v40; // [esp+38h] [ebp-54h]
  int *v41; // [esp+44h] [ebp-48h]
  int *v42; // [esp+4Ch] [ebp-40h]
  int *v43; // [esp+54h] [ebp-38h]
  int *v44; // [esp+5Ch] [ebp-30h]
  int *_Where; // [esp+64h] [ebp-28h]
  vostok::ai::selectors::disturbance_target_selector *v46; // [esp+6Ch] [ebp-20h]
  vostok::ai::selectors::pickup_item_target_selector *v47; // [esp+70h] [ebp-1Ch]
  vostok::ai::selectors::threat_target_selector *v48; // [esp+74h] [ebp-18h]
  vostok::ai::selectors::position_target_selector *v49; // [esp+78h] [ebp-14h]
  vostok::ai::selectors::sound_target_selector *v50; // [esp+7Ch] [ebp-10h]
  vostok::ai::selectors::animation_target_selector *v51; // [esp+80h] [ebp-Ch]
  vostok::ai::selectors::weapon_target_selector *v52; // [esp+84h] [ebp-8h]
  vostok::ai::selectors::enemy_target_selector *v53; // [esp+88h] [ebp-4h]

  if ( vostok::strings::equal(selector_type, "enemy") )
  {
    survarium::weapon_user_dead_state::finalize(v5);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v6, 0xC8u);
    v53 = (vostok::ai::selectors::enemy_target_selector *)operator new(0xC8u, _Where);
    if ( !v53 )
      return 0;
    vostok::ai::selectors::enemy_target_selector::enemy_target_selector(v53, world, memory, board, selector_type);
    return (vostok::ai::selectors::target_selector_base *)v7;
  }
  else if ( vostok::strings::equal(selector_type, "weapon") )
  {
    survarium::weapon_user_dead_state::finalize(v9);
    v44 = vostok::memory::doug_lea_allocator::malloc_impl(v10, 0x8Cu);
    v52 = (vostok::ai::selectors::weapon_target_selector *)operator new(0x8Cu, v44);
    if ( !v52 )
      return 0;
    vostok::ai::selectors::weapon_target_selector::weapon_target_selector(
      v52,
      world,
      memory,
      board,
      brain,
      selector_type);
    return (vostok::ai::selectors::target_selector_base *)v11;
  }
  else
  {
    v12 = vostok::strings::equal(selector_type, "animation");
    if ( v12 )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v12);
      v43 = vostok::memory::doug_lea_allocator::malloc_impl(v13, 0xCCu);
      v51 = (vostok::ai::selectors::animation_target_selector *)operator new(0xCCu, v43);
      if ( !v51 )
        return 0;
      vostok::ai::selectors::animation_target_selector::animation_target_selector(
        v51,
        world,
        memory,
        board,
        brain,
        selector_type);
      return (vostok::ai::selectors::target_selector_base *)v14;
    }
    else if ( vostok::strings::equal(selector_type, "sound") )
    {
      survarium::weapon_user_dead_state::finalize(v15);
      v42 = vostok::memory::doug_lea_allocator::malloc_impl(v16, 0xCCu);
      v50 = (vostok::ai::selectors::sound_target_selector *)operator new(0xCCu, v42);
      if ( !v50 )
        return 0;
      vostok::ai::selectors::sound_target_selector::sound_target_selector(
        v50,
        world,
        memory,
        board,
        brain,
        selector_type);
      return (vostok::ai::selectors::target_selector_base *)v17;
    }
    else if ( vostok::strings::equal(selector_type, "position") )
    {
      survarium::weapon_user_dead_state::finalize(v18);
      v41 = vostok::memory::doug_lea_allocator::malloc_impl(v19, 0xCCu);
      v49 = (vostok::ai::selectors::position_target_selector *)operator new(0xCCu, v41);
      if ( !v49 )
        return 0;
      vostok::ai::selectors::position_target_selector::position_target_selector(
        v49,
        world,
        memory,
        board,
        brain,
        selector_type);
      return (vostok::ai::selectors::target_selector_base *)v20;
    }
    else
    {
      v21 = vostok::strings::equal(selector_type, "threat");
      if ( v21 )
      {
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v21);
        v40 = vostok::memory::doug_lea_allocator::malloc_impl(v22, 0x40u);
        v48 = (vostok::ai::selectors::threat_target_selector *)operator new(0x40u, v40);
        if ( !v48 )
          return 0;
        vostok::ai::selectors::threat_target_selector::threat_target_selector(v48, world, memory, board, selector_type);
        return (vostok::ai::selectors::target_selector_base *)v23;
      }
      else
      {
        v24 = vostok::strings::equal(selector_type, "pickup_item");
        if ( v24 )
        {
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v24);
          v39 = vostok::memory::doug_lea_allocator::malloc_impl(v25, 0x40u);
          v47 = (vostok::ai::selectors::pickup_item_target_selector *)operator new(0x40u, v39);
          if ( !v47 )
            return 0;
          vostok::ai::selectors::pickup_item_target_selector::pickup_item_target_selector(
            v47,
            world,
            memory,
            board,
            selector_type);
          return (vostok::ai::selectors::target_selector_base *)v26;
        }
        else
        {
          v27 = vostok::strings::equal(selector_type, "disturbance");
          if ( v27 )
          {
            survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v27);
            v38 = vostok::memory::doug_lea_allocator::malloc_impl(v28, 0x40u);
            v46 = (vostok::ai::selectors::disturbance_target_selector *)operator new(0x40u, v38);
            if ( !v46 )
              return 0;
            vostok::ai::selectors::disturbance_target_selector::disturbance_target_selector(
              v46,
              world,
              memory,
              board,
              selector_type);
            return (vostok::ai::selectors::target_selector_base *)v29;
          }
          else
          {
            return 0;
          }
        }
      }
    }
  }
}
