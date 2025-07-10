void __userpurge vostok::variant<32>::set<vostok::ai::behaviour_cook_params>(
        vostok::variant<32> *this@<ecx>,
        vostok::ai::behaviour_cook_params *a2@<esi>,
        const vostok::ai::behaviour_cook_params *value)
{
  const vostok::configs::binary_config_value *behaviour_config; // ecx

  behaviour_config = a2[10].behaviour_config;
  if ( behaviour_config )
  {
    (*((void (__thiscall **)(const vostok::configs::binary_config_value *, vostok::ai::behaviour_cook_params *))behaviour_config->data.pointer
     + 1))(
      behaviour_config,
      a2 + 2);
    a2[10].behaviour_config = 0;
  }
  a2[11].behaviour_config = (const vostok::configs::binary_config_value *)vostok::detail::type_to_int<vostok::ai::behaviour_cook_params>::get();
  if ( a2 != (vostok::ai::behaviour_cook_params *)-8 )
    a2[2].behaviour_config = value->behaviour_config;
  a2[10].behaviour_config = (const vostok::configs::binary_config_value *)a2;
  a2->behaviour_config = (const vostok::configs::binary_config_value *)&vostok::detail::concrete_type_helper<vostok::ai::behaviour_cook_params>::`vftable';
}
