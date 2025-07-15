void __userpurge vostok::render::effect_material_base::compile_begin(
        vostok::render::effect_compiler *compiler@<ecx>,
        const vostok::render::custom_config_value *config@<eax>,
        vostok::render::effect_material_base *this,
        vostok::render::shader_configuration *vertex_shader_name,
        const char *geometry_shader_name,
        const char *pixel_shader_name,
        vostok::render::shader_configuration *shader_config)
{
  vostok::render::custom_config_value *v10; // ecx
  vostok::render::custom_config_value *v11; // ecx
  int data; // ebp
  vostok::render::custom_config_value *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  D3D11_BLEND v16; // edi
  vostok::render::effect_compiler *v17; // ecx
  D3D11_BLEND v18; // [esp-10h] [ebp-20h]
  D3D11_BLEND_OP v19; // [esp-Ch] [ebp-1Ch]
  D3D11_BLEND_OP v20; // [esp+0h] [ebp-10h]
  D3D11_CULL_MODE cull_mode; // [esp+1Ch] [ebp+Ch]

  if ( vostok::render::custom_config_value::value_exists(&key, (int)config) )
    *((_BYTE *)geometry_shader_name + 3) = (4
                                          * (int)vostok::render::custom_config_value::operator[](
                                                   v10,
                                                   (int)config,
                                                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&key)->data)
                                         | geometry_shader_name[3] & 3;
  cull_mode = D3D11_CULL_BACK;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A14, (int)config) )
    cull_mode = (D3D11_CULL_MODE)vostok::render::custom_config_value::operator[](
                                   v11,
                                   (int)config,
                                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_960A14)->data;
  *((_BYTE *)geometry_shader_name + 1) ^= (geometry_shader_name[1] ^ (8 * ((geometry_shader_name[3] & 0xFC) == 32))) & 8;
  data = -1;
  if ( vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_960AE0.m_techniques._M_t._M_header._M_data._M_left,
         (int)config) )
  {
    data = (int)vostok::render::custom_config_value::operator[](
                  v13,
                  (int)config,
                  (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_960AE0.m_techniques._M_t._M_header._M_data._M_left)->data;
  }
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)v13, (int)compiler);
  vostok::render::effect_compiler::begin_pass(
    v14,
    compiler,
    (char *)this,
    0,
    vertex_shader_name,
    (const vostok::render::shader_configuration *)geometry_shader_name);
  switch ( data )
  {
    case 0:
      vostok::render::effect_compiler::set_depth(v15, (int)compiler, 1, 1, D3D11_COMPARISON_LESS_EQUAL);
      vostok::render::effect_compiler::set_alpha_blend(
        D3D11_BLEND_ZERO,
        compiler,
        0,
        D3D11_BLEND_ONE,
        D3D11_BLEND_OP_ADD,
        D3D11_BLEND_ZERO,
        D3D11_BLEND_OP_ADD,
        v20);
      break;
    case 1:
      vostok::render::effect_compiler::set_depth(v15, (int)compiler, 1, 0, D3D11_COMPARISON_LESS_EQUAL);
      v19 = D3D11_BLEND_OP_ADD;
      v18 = D3D11_BLEND_SRC_ALPHA;
      v16 = D3D11_BLEND_INV_SRC_ALPHA;
      goto LABEL_14;
    case 2:
      vostok::render::effect_compiler::set_depth(v15, (int)compiler, 1, 0, D3D11_COMPARISON_LESS_EQUAL);
      v19 = D3D11_BLEND_OP_ADD;
      v18 = D3D11_BLEND_SRC_ALPHA;
      goto LABEL_13;
    case 3:
      vostok::render::effect_compiler::set_depth(v15, (int)compiler, 1, 0, D3D11_COMPARISON_LESS_EQUAL);
      vostok::render::effect_compiler::set_alpha_blend(
        D3D11_BLEND_SRC_COLOR,
        compiler,
        1,
        D3D11_BLEND_ZERO,
        D3D11_BLEND_OP_ADD,
        D3D11_BLEND_ZERO,
        D3D11_BLEND_OP_ADD,
        v20);
      vostok::render::effect_compiler::color_write_enable(
        v17,
        (int)compiler,
        D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
      vostok::render::effect_compiler::set_cull_mode(compiler, cull_mode);
      return;
    case 4:
      vostok::render::effect_compiler::set_depth(v15, (int)compiler, 1, 0, D3D11_COMPARISON_LESS_EQUAL);
      v19 = D3D11_BLEND_OP_REV_SUBTRACT;
      v18 = D3D11_BLEND_ONE;
LABEL_13:
      v16 = D3D11_BLEND_ONE;
LABEL_14:
      vostok::render::effect_compiler::set_alpha_blend(
        v16,
        compiler,
        1,
        v18,
        v19,
        D3D11_BLEND_ZERO,
        D3D11_BLEND_OP_ADD,
        v20);
      break;
    default:
      break;
  }
  vostok::render::effect_compiler::set_cull_mode(compiler, cull_mode);
}
