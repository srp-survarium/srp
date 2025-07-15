char __userpurge vostok::variant<32>::try_get<unsigned short>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        unsigned __int16 *out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<unsigned short>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<unsigned short>::get() )
  {
    *out_value = *(_WORD *)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<unsigned short>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<unsigned short>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<unsigned short>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<unsigned short>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::render::bake_decal_cook_parameters *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::render::bake_decal_cook_parameters **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<vostok::render::bake_decal_cook_parameters *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::render::bake_decal_cook_parameters *>::get() )
  {
    *out_value = *(vostok::render::bake_decal_cook_parameters **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::bake_decal_cook_parameters *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::bake_decal_cook_parameters *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::bake_decal_cook_parameters *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::bake_decal_cook_parameters *>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::render::binary_shader_cook_data *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::render::binary_shader_cook_data **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<vostok::render::binary_shader_cook_data *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::render::binary_shader_cook_data *>::get() )
  {
    *out_value = *(vostok::render::binary_shader_cook_data **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::binary_shader_cook_data *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::binary_shader_cook_data *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::binary_shader_cook_data *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::binary_shader_cook_data *>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
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
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::particle::engine *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::particle::engine **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<vostok::particle::engine *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::particle::engine *>::get() )
  {
    *out_value = *(vostok::particle::engine **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::particle::engine *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::particle::engine *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::particle::engine *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::particle::engine *>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
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
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<survarium::inventory_cooker_data *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        survarium::inventory_cooker_data **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<survarium::inventory_cooker_data *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<survarium::inventory_cooker_data *>::get() )
  {
    *out_value = *(survarium::inventory_cooker_data **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<survarium::inventory_cooker_data *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::inventory_cooker_data *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<survarium::inventory_cooker_data *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::inventory_cooker_data *>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
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
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
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
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
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
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
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

  if ( `vostok::variant<32>::try_get<vostok::render::engine::world *>'::`5'::debug_macro_helper_ignore_always
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
      if ( !`vostok::variant<32>::try_get<vostok::render::engine::world *>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<void *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        void **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<void *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<void *>::get() )
  {
    *out_value = *(void **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<void *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<void *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<void *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<void *>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
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
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::configs::binary_config_value const *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        const vostok::configs::binary_config_value **out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<vostok::configs::binary_config_value const *>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::configs::binary_config_value const *>::get() )
  {
    *out_value = *(const vostok::configs::binary_config_value **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::configs::binary_config_value const *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::configs::binary_config_value const *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::configs::binary_config_value const *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::configs::binary_config_value const *>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::collision::animated_object_cook_data>@<al>(
        vostok::variant<32> *this@<ecx>,
        const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *a2@<esi>,
        vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *out_value)
{
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v3; // ebx
  unsigned int v4; // eax

  v3 = out_value;
  if ( `vostok::variant<32>::try_get<vostok::collision::animated_object_cook_data>'::`5'::debug_macro_helper_ignore_always
    || a2[11].m_object == (vostok::particle::particle_system_instance_impl *)vostok::detail::type_to_int<vostok::collision::animated_object_cook_data>::get() )
  {
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      a2 + 2,
      v3);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      a2 + 3,
      v3 + 1);
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<vostok::collision::animated_object_cook_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::collision::animated_object_cook_data>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<vostok::collision::animated_object_cook_data>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::collision::animated_object_cook_data>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>@<al>(
        vostok::variant<32> *this@<ecx>,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *a2@<esi>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *out_value)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v3; // ebx
  unsigned int v4; // eax

  v3 = out_value;
  if ( `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`5'::debug_macro_helper_ignore_always
    || a2[11].m_object == (vostok::resources::managed_resource *)vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::get() )
  {
    v3->m_object = a2[2].m_object;
    v3[1].m_object = a2[3].m_object;
    v3[2].m_object = a2[4].m_object;
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
      a2 + 5,
      v3 + 3);
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>@<al>(
        vostok::variant<32> *this@<ecx>,
        const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *a2@<esi>,
        vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *out_value)
{
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v3; // ebx
  unsigned int v4; // eax

  v3 = out_value;
  if ( `vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>'::`5'::debug_macro_helper_ignore_always
    || a2[11].m_object == (vostok::particle::particle_system_instance_impl *)vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::get() )
  {
    v3->m_object = a2[2].m_object;
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      a2 + 3,
      v3 + 1);
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __usercall vostok::variant<32>::try_get<survarium::anomaly_cook_data>@<al>(
        vostok::variant<32> *this@<esi>,
        survarium::anomaly_cook_data *out_value@<edi>)
{
  unsigned int v2; // eax
  bool v4; // [esp+7h] [ebp-1h] BYREF

  if ( `vostok::variant<32>::try_get<survarium::anomaly_cook_data>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<survarium::anomaly_cook_data>::get() )
  {
    *out_value = *(survarium::anomaly_cook_data *)this->m_storage;
    return 1;
  }
  else
  {
    v2 = `vostok::variant<32>::try_get<survarium::anomaly_cook_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::anomaly_cook_data>'::`8'::occurances_left == -1 )
      v2 = 10;
    `vostok::variant<32>::try_get<survarium::anomaly_cook_data>'::`8'::occurances_left = v2 - 1;
    if ( v2 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::anomaly_cook_data>'::`5'::debug_macro_helper_ignore_always )
      {
        v4 = 0;
        vostok::debug::on_error(
          &v4,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || v4 )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __usercall vostok::variant<32>::try_get<survarium::artefact_cook_data>@<al>(
        vostok::variant<32> *this@<esi>,
        survarium::artefact_cook_data *out_value@<edi>)
{
  unsigned int v2; // eax

  if ( !`vostok::variant<32>::try_get<survarium::artefact_cook_data>'::`5'::debug_macro_helper_ignore_always
    && this->m_type_id != vostok::detail::type_to_int<survarium::artefact_cook_data>::get() )
  {
    v2 = `vostok::variant<32>::try_get<survarium::artefact_cook_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::artefact_cook_data>'::`8'::occurances_left == -1 )
      v2 = 10;
    `vostok::variant<32>::try_get<survarium::artefact_cook_data>'::`8'::occurances_left = v2 - 1;
    JUMPOUT(0x1CA194);
  }
  *out_value = *(survarium::artefact_cook_data *)this->m_storage;
  return 1;
}


char __usercall vostok::variant<32>::try_get<survarium::booby_trap_core_query_data>@<al>(
        vostok::variant<32> *this@<eax>,
        vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *out_value@<esi>)
{
  unsigned int v3; // eax
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *m_storage; // edi
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  if ( `vostok::variant<32>::try_get<survarium::booby_trap_core_query_data>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<survarium::booby_trap_core_query_data>::get() )
  {
    m_storage = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)this->m_storage;
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      m_storage,
      out_value);
    out_value[1].m_object = m_storage[1].m_object;
    out_value[2].m_object = m_storage[2].m_object;
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<survarium::booby_trap_core_query_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::booby_trap_core_query_data>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<survarium::booby_trap_core_query_data>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::booby_trap_core_query_data>'::`5'::debug_macro_helper_ignore_always )
      {
        v6 = 0;
        vostok::debug::on_error(
          &v6,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || v6 )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<eax>,
        survarium::booby_trap_set_cook_data *out_value)
{
  unsigned int v4; // eax
  survarium::booby_trap_set_cook_data *v6; // edi
  _DWORD *v7; // esi

  if ( `vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::get() )
  {
    v6 = out_value;
    v7 = (_DWORD *)(a2 + 8);
    *(_DWORD *)&out_value->is_local_player = *v7++;
    v6 = (survarium::booby_trap_set_cook_data *)((char *)v6 + 4);
    *(_DWORD *)&v6->is_local_player = *v7;
    v6->physics_world = (vostok::physics::world *)v7[1];
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __usercall vostok::variant<32>::try_get<survarium::gather_victory_items_rule_query_data>@<al>(
        vostok::variant<32> *this@<esi>,
        survarium::gather_victory_items_rule_query_data *out_value@<edi>)
{
  unsigned int v2; // eax
  bool v4; // [esp+7h] [ebp-1h] BYREF

  if ( `vostok::variant<32>::try_get<survarium::gather_victory_items_rule_query_data>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<survarium::gather_victory_items_rule_query_data>::get() )
  {
    *out_value = *(survarium::gather_victory_items_rule_query_data *)this->m_storage;
    return 1;
  }
  else
  {
    v2 = `vostok::variant<32>::try_get<survarium::gather_victory_items_rule_query_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::gather_victory_items_rule_query_data>'::`8'::occurances_left == -1 )
      v2 = 10;
    `vostok::variant<32>::try_get<survarium::gather_victory_items_rule_query_data>'::`8'::occurances_left = v2 - 1;
    if ( v2 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::gather_victory_items_rule_query_data>'::`5'::debug_macro_helper_ignore_always )
      {
        v4 = 0;
        vostok::debug::on_error(
          &v4,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || v4 )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<survarium::grenade_cook_data>@<al>(
        vostok::variant<32> *this@<ecx>,
        const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *a2@<esi>,
        vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *out_value)
{
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v3; // ebx
  unsigned int v4; // eax

  v3 = out_value;
  if ( `vostok::variant<32>::try_get<survarium::grenade_cook_data>'::`5'::debug_macro_helper_ignore_always
    || a2[11].m_object == (vostok::particle::particle_system_instance_impl *)vostok::detail::type_to_int<survarium::grenade_cook_data>::get() )
  {
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      a2 + 2,
      v3);
    v3[1].m_object = a2[3].m_object;
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<survarium::grenade_cook_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::grenade_cook_data>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<survarium::grenade_cook_data>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::grenade_cook_data>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __usercall vostok::variant<32>::try_get<survarium::grenade_set_cook_data>@<al>(
        vostok::variant<32> *this@<esi>,
        survarium::grenade_set_cook_data *out_value@<edi>)
{
  unsigned int v2; // eax
  bool v4; // [esp+7h] [ebp-1h] BYREF

  if ( `vostok::variant<32>::try_get<survarium::grenade_set_cook_data>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<survarium::grenade_set_cook_data>::get() )
  {
    *out_value = *(survarium::grenade_set_cook_data *)this->m_storage;
    return 1;
  }
  else
  {
    v2 = `vostok::variant<32>::try_get<survarium::grenade_set_cook_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::grenade_set_cook_data>'::`8'::occurances_left == -1 )
      v2 = 10;
    `vostok::variant<32>::try_get<survarium::grenade_set_cook_data>'::`8'::occurances_left = v2 - 1;
    if ( v2 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::grenade_set_cook_data>'::`5'::debug_macro_helper_ignore_always )
      {
        v4 = 0;
        vostok::debug::on_error(
          &v4,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || v4 )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<survarium::kd_stats_rule_query_data>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        survarium::kd_stats_rule_query_data *out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<survarium::kd_stats_rule_query_data>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<survarium::kd_stats_rule_query_data>::get() )
  {
    out_value->match_options = *(const survarium::match_options **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<survarium::kd_stats_rule_query_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::kd_stats_rule_query_data>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<survarium::kd_stats_rule_query_data>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::kd_stats_rule_query_data>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::render::output_window_configuration>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<eax>,
        vostok::render::output_window_configuration *out_value)
{
  unsigned int v4; // eax

  if ( `vostok::variant<32>::try_get<vostok::render::output_window_configuration>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::render::output_window_configuration>::get() )
  {
    qmemcpy(out_value, (const void *)(a2 + 8), sizeof(vostok::render::output_window_configuration));
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<vostok::render::output_window_configuration>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::output_window_configuration>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<vostok::render::output_window_configuration>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::output_window_configuration>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<survarium::player_initial_info>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<eax>,
        survarium::player_initial_info *out_value)
{
  unsigned int v4; // eax

  if ( `vostok::variant<32>::try_get<survarium::player_initial_info>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<survarium::player_initial_info>::get() )
  {
    qmemcpy(out_value, (const void *)(a2 + 8), sizeof(survarium::player_initial_info));
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<survarium::player_initial_info>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::player_initial_info>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<survarium::player_initial_info>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::player_initial_info>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<survarium::player_respawn_rule_query_data>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<eax>,
        survarium::player_respawn_rule_query_data *out_value)
{
  unsigned int v4; // eax
  survarium::player_respawn_rule_query_data *v6; // edi
  int v7; // esi

  if ( `vostok::variant<32>::try_get<survarium::player_respawn_rule_query_data>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<survarium::player_respawn_rule_query_data>::get() )
  {
    v6 = out_value;
    v7 = a2 + 8;
    out_value->match_options = *(const survarium::match_options **)v7;
    v7 += 4;
    v6 = (survarium::player_respawn_rule_query_data *)((char *)v6 + 4);
    v6->match_options = *(const survarium::match_options **)v7;
    *(_DWORD *)&v6->single_player = *(_DWORD *)(v7 + 4);
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<survarium::player_respawn_rule_query_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::player_respawn_rule_query_data>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<survarium::player_respawn_rule_query_data>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::player_respawn_rule_query_data>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<survarium::pvp_match_core_query_user_data>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<eax>,
        survarium::pvp_match_core_query_user_data *out_value)
{
  unsigned int v4; // eax

  if ( `vostok::variant<32>::try_get<survarium::pvp_match_core_query_user_data>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<survarium::pvp_match_core_query_user_data>::get() )
  {
    qmemcpy(out_value, (const void *)(a2 + 8), sizeof(survarium::pvp_match_core_query_user_data));
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<survarium::pvp_match_core_query_user_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::pvp_match_core_query_user_data>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<survarium::pvp_match_core_query_user_data>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::pvp_match_core_query_user_data>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::render::render_texture_cook_parameters>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<eax>,
        vostok::render::render_texture_cook_parameters *out_value)
{
  unsigned int v4; // eax
  vostok::render::render_texture_cook_parameters *v6; // edi
  unsigned int *v7; // esi

  if ( `vostok::variant<32>::try_get<vostok::render::render_texture_cook_parameters>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::render::render_texture_cook_parameters>::get() )
  {
    v6 = out_value;
    v7 = (unsigned int *)(a2 + 8);
    out_value->mip_level_cut = *v7++;
    v6 = (vostok::render::render_texture_cook_parameters *)((char *)v6 + 4);
    v6->mip_level_cut = *v7++;
    v6 = (vostok::render::render_texture_cook_parameters *)((char *)v6 + 4);
    v6->mip_level_cut = *v7;
    v6->num_last_mips_used = v7[1];
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<vostok::render::render_texture_cook_parameters>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::render_texture_cook_parameters>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<vostok::render::render_texture_cook_parameters>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::render_texture_cook_parameters>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
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
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<eax>,
        vostok::sound::sound_scene_creation_params *out_value)
{
  unsigned int v4; // eax
  vostok::sound::sound_scene_creation_params *v6; // edi
  unsigned int *v7; // esi

  if ( `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::sound::sound_scene_creation_params>::get() )
  {
    v6 = out_value;
    v7 = (unsigned int *)(a2 + 8);
    out_value->proxies_count = *v7++;
    v6 = (vostok::sound::sound_scene_creation_params *)((char *)v6 + 4);
    v6->proxies_count = *v7;
    v6->propagators_count = v7[1];
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::sound::sound_scene_creation_params>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>@<al>(
        vostok::variant<32> *this@<ecx>,
        const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *a2@<esi>,
        vostok::render::static_model_instance_user_data *out_value)
{
  vostok::render::static_model_instance_user_data *v3; // ebx
  unsigned int v4; // eax

  v3 = out_value;
  if ( `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`5'::debug_macro_helper_ignore_always
    || a2[11].m_object == (survarium::pure_game_effect_emitter_base *)vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::get() )
  {
    v3->config = (const vostok::configs::binary_config_value *)a2[2].m_object;
    v3->sound_world = (vostok::sound::world *)a2[3].m_object;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      a2 + 4,
      &v3->sound_scene);
    return 1;
  }
  else
  {
    v4 = `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`8'::occurances_left == -1 )
      v4 = 10;
    `vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`8'::occurances_left = v4 - 1;
    if ( v4 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::render::static_model_instance_user_data>'::`5'::debug_macro_helper_ignore_always )
      {
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __usercall vostok::variant<32>::try_get<survarium::timelimit_rule_query_data>@<al>(
        vostok::variant<32> *this@<esi>,
        survarium::timelimit_rule_query_data *out_value@<edi>)
{
  unsigned int v2; // eax
  bool v4; // [esp+7h] [ebp-1h] BYREF

  if ( `vostok::variant<32>::try_get<survarium::timelimit_rule_query_data>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<survarium::timelimit_rule_query_data>::get() )
  {
    *out_value = *(survarium::timelimit_rule_query_data *)this->m_storage;
    return 1;
  }
  else
  {
    v2 = `vostok::variant<32>::try_get<survarium::timelimit_rule_query_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::timelimit_rule_query_data>'::`8'::occurances_left == -1 )
      v2 = 10;
    `vostok::variant<32>::try_get<survarium::timelimit_rule_query_data>'::`8'::occurances_left = v2 - 1;
    if ( v2 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::timelimit_rule_query_data>'::`5'::debug_macro_helper_ignore_always )
      {
        v4 = 0;
        vostok::debug::on_error(
          &v4,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || v4 )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __usercall vostok::variant<32>::try_get<survarium::weapon_cook_data>@<al>(
        vostok::variant<32> *this@<esi>,
        survarium::weapon_cook_data *out_value@<edi>)
{
  unsigned int v2; // eax
  bool v4; // [esp+7h] [ebp-1h] BYREF

  if ( `vostok::variant<32>::try_get<survarium::weapon_cook_data>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<survarium::weapon_cook_data>::get() )
  {
    *out_value = *(survarium::weapon_cook_data *)this->m_storage;
    return 1;
  }
  else
  {
    v2 = `vostok::variant<32>::try_get<survarium::weapon_cook_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<survarium::weapon_cook_data>'::`8'::occurances_left == -1 )
      v2 = 10;
    `vostok::variant<32>::try_get<survarium::weapon_cook_data>'::`8'::occurances_left = v2 - 1;
    if ( v2 )
    {
      if ( !`vostok::variant<32>::try_get<survarium::weapon_cook_data>'::`5'::debug_macro_helper_ignore_always )
      {
        v4 = 0;
        vostok::debug::on_error(
          &v4,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || v4 )
          __debugbreak();
      }
    }
    return 0;
  }
}


char __userpurge vostok::variant<32>::try_get<vostok::configs::binary_config_value>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::configs::binary_config_value *out_value)
{
  unsigned int v3; // eax

  if ( `vostok::variant<32>::try_get<vostok::configs::binary_config_value>'::`5'::debug_macro_helper_ignore_always
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::configs::binary_config_value>::get() )
  {
    vostok::configs::binary_config_value::operator=((vostok::configs::binary_config_value *)(a2 + 8), out_value);
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
        HIBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value + 3,
          process_error_false,
          (bool *)"(m_type_id) == (::vostok::detail::type_to_int<T>::get())",
          "c:\\survarium.deploy\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          (const char *)0x98);
        if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
          __debugbreak();
      }
    }
    return 0;
  }
}
