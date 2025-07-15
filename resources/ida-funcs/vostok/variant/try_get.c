char __thiscall vostok::variant<32>::try_get<unsigned char>(vostok::variant<32> *this, unsigned __int8 *out_value)
{
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  if ( `vostok::variant<32>::try_get<unsigned char>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<unsigned char>::get() )
  {
    *out_value = this->m_storage[0];
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<unsigned char>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<unsigned char>'::`8'::occurances_left = 10;
    if ( `vostok::variant<32>::try_get<unsigned char>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<unsigned char>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<unsigned char>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __thiscall vostok::variant<32>::try_get<unsigned short>(vostok::variant<32> *this, unsigned __int16 *out_value)
{
  _BYTE *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2
    || `vostok::variant<32>::try_get<unsigned short>'::`5'::debug_macro_helper_ignore_always
    || (vostok::detail::type_to_int<unsigned short>::get(), survarium::weapon_user_dead_state::finalize(v3), *v4) )
  {
    *out_value = *(_WORD *)this->m_storage;
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<unsigned short>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<unsigned short>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v4);
    if ( `vostok::variant<32>::try_get<unsigned short>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<unsigned short>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<unsigned short>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::render::effect_compile_data *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::render::effect_compile_data **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<vostok::render::effect_compile_data *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::render::effect_compile_data *>::get() )
  {
    *out_value = *(vostok::render::effect_compile_data **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::effect_compile_data *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::effect_compile_data *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::effect_compile_data *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::effect_compile_data *>'::`5'::debug_macro_helper_ignore_always )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::render::effect_compile_data *>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __thiscall vostok::variant<32>::try_get<vostok::particle::engine *>(
        vostok::variant<32> *this,
        vostok::particle::engine **out_value)
{
  _BYTE *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2
    || `vostok::variant<32>::try_get<vostok::particle::engine *>'::`5'::debug_macro_helper_ignore_always
    || (vostok::detail::type_to_int<vostok::particle::engine *>::get(),
        survarium::weapon_user_dead_state::finalize(v3),
        *v4) )
  {
    *out_value = *(vostok::particle::engine **)this->m_storage;
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<vostok::particle::engine *>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<vostok::particle::engine *>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v4);
    if ( `vostok::variant<32>::try_get<vostok::particle::engine *>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<vostok::particle::engine *>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::particle::engine *>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::render::grass_loading_data *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::render::grass_loading_data **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<vostok::render::grass_loading_data *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::render::grass_loading_data *>::get() )
  {
    *out_value = *(vostok::render::grass_loading_data **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::grass_loading_data *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::grass_loading_data *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::grass_loading_data *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::grass_loading_data *>'::`5'::debug_macro_helper_ignore_always )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::render::grass_loading_data *>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __thiscall vostok::variant<32>::try_get<survarium::inventory_cooker_data *>(
        vostok::variant<32> *this,
        survarium::inventory_cooker_data **out_value)
{
  _BYTE *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2
    || `vostok::variant<32>::try_get<survarium::inventory_cooker_data *>'::`5'::debug_macro_helper_ignore_always
    || (vostok::detail::type_to_int<survarium::inventory_cooker_data *>::get(),
        survarium::weapon_user_dead_state::finalize(v3),
        *v4) )
  {
    *out_value = *(survarium::inventory_cooker_data **)this->m_storage;
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<survarium::inventory_cooker_data *>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<survarium::inventory_cooker_data *>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v4);
    if ( `vostok::variant<32>::try_get<survarium::inventory_cooker_data *>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<survarium::inventory_cooker_data *>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<survarium::inventory_cooker_data *>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::render::material_effects_instance_cook_data *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::render::material_effects_instance_cook_data **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<vostok::render::material_effects_instance_cook_data *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get() )
  {
    *out_value = *(vostok::render::material_effects_instance_cook_data **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::material_effects_instance_cook_data *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::material_effects_instance_cook_data *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::material_effects_instance_cook_data *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::material_effects_instance_cook_data *>'::`5'::debug_macro_helper_ignore_always )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::render::material_effects_instance_cook_data *>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __thiscall vostok::variant<32>::try_get<survarium::player_parameters_cooker_data *>(
        vostok::variant<32> *this,
        survarium::player_parameters_cooker_data **out_value)
{
  _BYTE *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2
    || `vostok::variant<32>::try_get<survarium::player_parameters_cooker_data *>'::`5'::debug_macro_helper_ignore_always
    || (vostok::detail::type_to_int<survarium::player_parameters_cooker_data *>::get(),
        survarium::weapon_user_dead_state::finalize(v3),
        *v4) )
  {
    *out_value = *(survarium::player_parameters_cooker_data **)this->m_storage;
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<survarium::player_parameters_cooker_data *>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<survarium::player_parameters_cooker_data *>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v4);
    if ( `vostok::variant<32>::try_get<survarium::player_parameters_cooker_data *>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<survarium::player_parameters_cooker_data *>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<survarium::player_parameters_cooker_data *>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::render::skeleton_combined_cook_data **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::render::skeleton_combined_cook_data *>::get() )
  {
    *out_value = *(vostok::render::skeleton_combined_cook_data **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>'::`5'::debug_macro_helper_ignore_always )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::render::skeleton_combined_cook_data *>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::physics::world *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::physics::world **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<vostok::physics::world *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::physics::world *>::get() )
  {
    *out_value = *(vostok::physics::world **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::physics::world *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::physics::world *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::physics::world *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::physics::world *>'::`5'::debug_macro_helper_ignore_always )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::physics::world *>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<survarium::base_game_scene *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        survarium::base_game_scene **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<survarium::base_game_scene *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<survarium::base_game_scene *>::get() )
  {
    *out_value = *(survarium::base_game_scene **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<survarium::base_game_scene *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::base_game_scene *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<survarium::base_game_scene *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::base_game_scene *>'::`5'::debug_macro_helper_ignore_always )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          &`vostok::variant<32>::try_get<survarium::base_game_scene *>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::render::engine::world *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::render::engine::world **out_value)
{
  unsigned int v3; // eax

  if ( LOBYTE(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[1])
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::render::engine::world *>::get() )
  {
    *out_value = *(vostok::render::engine::world **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::engine::world *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::engine::world *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::engine::world *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !LOBYTE(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[1]) )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          (bool *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[1],
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<survarium::player_profile const *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        const survarium::player_profile **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<survarium::player_profile const *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<survarium::player_profile const *>::get() )
  {
    *out_value = *(const survarium::player_profile **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<survarium::player_profile const *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::player_profile const *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<survarium::player_profile const *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::player_profile const *>'::`5'::debug_macro_helper_ignore_always )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          &`vostok::variant<32>::try_get<survarium::player_profile const *>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __thiscall vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>(
        vostok::variant<32> *this,
        survarium::animation_analysis_result_cook_user_data *out_value)
{
  _BYTE *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  bool do_debug_break; // [esp+1Bh] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2
    || `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`5'::debug_macro_helper_ignore_always
    || (vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::get(),
        survarium::weapon_user_dead_state::finalize(v3),
        *v4) )
  {
    out_value->legs_count = *(_DWORD *)this->m_storage;
    out_value->legs = *(const survarium::leg_info **)&this->m_storage[4];
    out_value->skeleton = *(vostok::animation::skeleton **)&this->m_storage[8];
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
      &out_value->animation,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&this->m_storage[12]);
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v4);
    if ( `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __usercall vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>@<al>(
        vostok::variant<32> *this@<eax>,
        vostok::animation::animation_collection_cook_user_data *out_value@<edi>)
{
  unsigned int v3; // eax
  bool do_debug_break; // [esp+Bh] [ebp-1h] BYREF

  if ( BYTE2(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[3])
    || this->m_type_id == vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::get() )
  {
    out_value->val = *(const vostok::configs::binary_config_value **)this->m_storage;
    vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
      &out_value->cfg_ptr,
      (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&this->m_storage[4]);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !BYTE2(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[3]) )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[3]
        + 2,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __thiscall vostok::variant<32>::try_get<vostok::ai::behaviour_cook_params>(
        vostok::variant<32> *this,
        vostok::ai::behaviour_cook_params *out_value)
{
  _BYTE *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2
    || LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[2])
    || (vostok::detail::type_to_int<vostok::ai::behaviour_cook_params>::get(),
        survarium::weapon_user_dead_state::finalize(v3),
        *v4) )
  {
    out_value->behaviour_config = *(const vostok::configs::binary_config_value **)this->m_storage;
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<vostok::ai::behaviour_cook_params>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<vostok::ai::behaviour_cook_params>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v4);
    if ( `vostok::variant<32>::try_get<vostok::ai::behaviour_cook_params>'::`8'::occurances_left-- )
    {
      if ( !LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[2]) )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[2],
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __thiscall vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>(
        vostok::variant<32> *this,
        survarium::booby_trap_set_cook_data *out_value)
{
  _BYTE *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2
    || `vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>'::`5'::debug_macro_helper_ignore_always
    || (vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::get(),
        survarium::weapon_user_dead_state::finalize(v3),
        *v4) )
  {
    *out_value = *(survarium::booby_trap_set_cook_data *)this->m_storage;
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v4);
    if ( `vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __usercall vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>@<al>(
        vostok::variant<32> *this@<esi>,
        vostok::ai::brain_unit_cook_params *out_value@<edi>,
        int a3@<ecx>)
{
  unsigned int v3; // eax
  bool do_debug_break; // [esp+1h] [ebp-1h] BYREF

  do_debug_break = HIBYTE(a3);
  if ( `vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<vostok::ai::brain_unit_cook_params>::get() )
  {
    out_value->sound_world_user = *(vostok::sound::world_user **)this->m_storage;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
      &out_value->sound_scene,
      (const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_storage[4]);
    out_value->npc = *(vostok::ai::npc **)&this->m_storage[8];
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __usercall vostok::variant<32>::try_get<vostok::render::output_window_configuration>@<al>(
        vostok::variant<32> *this@<esi>,
        vostok::render::output_window_configuration *out_value@<edi>,
        int a3@<ecx>)
{
  unsigned int v3; // eax
  bool do_debug_break; // [esp+1h] [ebp-1h] BYREF

  do_debug_break = HIBYTE(a3);
  if ( `vostok::variant<32>::try_get<vostok::render::output_window_configuration>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<vostok::render::output_window_configuration>::get() )
  {
    *out_value = *(vostok::render::output_window_configuration *)this->m_storage;
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::output_window_configuration>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::output_window_configuration>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::output_window_configuration>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::output_window_configuration>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::render::output_window_configuration>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __usercall vostok::variant<32>::try_get<survarium::player_initial_info>@<al>(
        vostok::variant<32> *this@<esi>,
        survarium::player_initial_info *out_value@<edi>,
        int a3@<ecx>)
{
  unsigned int v3; // eax
  bool do_debug_break; // [esp+1h] [ebp-1h] BYREF

  do_debug_break = HIBYTE(a3);
  if ( `vostok::variant<32>::try_get<survarium::player_initial_info>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<survarium::player_initial_info>::get() )
  {
    *out_value = *(survarium::player_initial_info *)this->m_storage;
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<survarium::player_initial_info>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::player_initial_info>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<survarium::player_initial_info>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::player_initial_info>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<survarium::player_initial_info>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::render::scene_configuration>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::render::scene_configuration *out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<vostok::render::scene_configuration>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::render::scene_configuration>::get() )
  {
    *out_value = *(vostok::render::scene_configuration *)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::scene_configuration>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::scene_configuration>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::scene_configuration>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::scene_configuration>'::`5'::debug_macro_helper_ignore_always )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::render::scene_configuration>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __thiscall vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>(
        vostok::variant<32> *this,
        vostok::sound::sound_collection_cook_user_data *out_value)
{
  vostok::configs::binary_config **v4; // eax
  vostok::configs::binary_config *v6; // [esp+18h] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v7; // [esp+2Ch] [ebp-8h] BYREF
  bool v8; // [esp+31h] [ebp-3h]
  char v9; // [esp+32h] [ebp-2h]
  bool do_debug_break; // [esp+33h] [ebp-1h] BYREF

  v9 = 1;
  if ( `vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`5'::debug_macro_helper_ignore_always
    || (v8 = this->m_type_id == vostok::detail::type_to_int<vostok::sound::sound_collection_cook_user_data>::get()) )
  {
    out_value->val = *(const vostok::configs::binary_config_value **)this->m_storage;
    boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &v7,
      (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&this->m_storage[4]);
    v6 = *v4;
    *v4 = out_value->cfg_ptr.m_object;
    out_value->cfg_ptr.m_object = v6;
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v7);
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`8'::occurances_left = 10;
    if ( `vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::sound::sound_collection_cook_user_data>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __thiscall vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>(
        vostok::variant<32> *this,
        vostok::sound::sound_scene_creation_params *out_value)
{
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  if ( `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::get() )
  {
    *out_value = *(vostok::sound::sound_scene_creation_params *)this->m_storage;
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`8'::occurances_left = 10;
    if ( `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __thiscall vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>(
        vostok::variant<32> *this,
        vostok::render::static_model_instance_user_data *out_value)
{
  unsigned int v3; // eax
  vostok::render::static_model_instance_user_data *v5; // eax

  if ( `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::get() )
  {
    v5 = out_value;
    out_value->config = *(const vostok::configs::binary_config_value **)this->m_storage;
    v5->sound_world = *(vostok::sound::world **)&this->m_storage[4];
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
      &v5->sound_scene,
      (const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_storage[8]);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`5'::debug_macro_helper_ignore_always )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __usercall vostok::variant<32>::try_get<vostok::configs::binary_config_value>@<al>(
        vostok::variant<32> *this@<esi>,
        vostok::configs::binary_config_value *out_value@<edi>,
        int a3@<ecx>)
{
  unsigned int v3; // eax
  bool do_debug_break; // [esp+1h] [ebp-1h] BYREF

  do_debug_break = HIBYTE(a3);
  if ( `vostok::variant<32>::try_get<vostok::configs::binary_config_value>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<vostok::configs::binary_config_value>::get() )
  {
    *out_value = *(vostok::configs::binary_config_value *)this->m_storage;
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::configs::binary_config_value>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::configs::binary_config_value>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::configs::binary_config_value>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::configs::binary_config_value>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::configs::binary_config_value>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __thiscall vostok::variant<32>::try_get<enum survarium::affects_applying_type_enum>(
        vostok::variant<32> *this,
        survarium::affects_applying_type_enum *out_value)
{
  _BYTE *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( !*v2
    || `vostok::variant<32>::try_get<enum survarium::affects_applying_type_enum>'::`5'::debug_macro_helper_ignore_always
    || (vostok::detail::type_to_int<enum survarium::affects_applying_type_enum>::get(),
        survarium::weapon_user_dead_state::finalize(v3),
        *v4) )
  {
    *out_value = *(survarium::affects_applying_type_enum *)this->m_storage;
    return 1;
  }
  else
  {
    if ( `vostok::variant<32>::try_get<enum survarium::affects_applying_type_enum>'::`8'::occurances_left == -1 )
      `vostok::variant<32>::try_get<enum survarium::affects_applying_type_enum>'::`8'::occurances_left = vostok::ui::ui_dialog::input_priority((survarium::game_world *)(unsigned __int8)*v4);
    if ( `vostok::variant<32>::try_get<enum survarium::affects_applying_type_enum>'::`8'::occurances_left-- )
    {
      if ( !`vostok::variant<32>::try_get<enum survarium::affects_applying_type_enum>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<enum survarium::affects_applying_type_enum>'::`5'::debug_macro_helper_ignore_always,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}
