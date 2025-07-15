void __thiscall vostok::particle::color_matrix::load<vostok::configs::binary_config_value>(
        vostok::particle::color_matrix *this,
        vostok::configs::binary_config_value config)
{
  vostok::fixed_string<16> *v2; // ecx
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::variant<32> **v5; // eax
  vostok::particle::enum_evaluate_type v6; // eax
  vostok::fixed_string<16> *v7; // ecx
  vostok::configs::binary_config_value *v8; // eax
  vostok::configs::binary_config_value *v9; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  const vostok::variant<32> **v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  const vostok::variant<32> **v13; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v14; // ecx
  const vostok::variant<32> **v15; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v16; // ecx
  const vostok::variant<32> **v17; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v18; // ecx
  const vostok::variant<32> **v19; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v20; // ecx
  const vostok::variant<32> **v21; // eax
  const vostok::configs::binary_config_value *v22; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v23; // ecx
  const vostok::variant<32> **v24; // eax
  float *v25; // eax
  float v26; // ecx
  float v27; // edx
  vostok::particle::color_matrix_point_type *v28; // eax
  const vostok::configs::binary_config_value *v29; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v30; // ecx
  const vostok::variant<32> **v31; // eax
  vostok::particle::color_matrix_point_type *v32; // eax
  float v34; // [esp+60h] [ebp-ACh]
  const vostok::variant<32> *v35; // [esp+64h] [ebp-A8h]
  const vostok::variant<32> *v36; // [esp+68h] [ebp-A4h]
  const vostok::variant<32> *v37; // [esp+6Ch] [ebp-A0h]
  vostok::math::float2 v38; // [esp+70h] [ebp-9Ch] BYREF
  const vostok::configs::binary_config_value *element; // [esp+78h] [ebp-94h]
  vostok::particle::color_matrix_point_type *point; // [esp+7Ch] [ebp-90h]
  vostok::configs::binary_config_value *v41; // [esp+80h] [ebp-8Ch]
  vostok::configs::binary_config_value column_it; // [esp+84h] [ebp-88h] BYREF
  const vostok::configs::binary_config_value *columns_config; // [esp+A0h] [ebp-6Ch]
  vostok::configs::binary_config_value row_it; // [esp+A4h] [ebp-68h] BYREF
  unsigned int num_columns; // [esp+C0h] [ebp-4Ch]
  unsigned int num_rows; // [esp+C4h] [ebp-48h]
  vostok::fixed_string<16> row_name; // [esp+C8h] [ebp-44h] BYREF
  unsigned int row_index; // [esp+E4h] [ebp-28h]
  const vostok::configs::binary_config_value *rows_config; // [esp+E8h] [ebp-24h]
  vostok::fixed_string<16> column_name; // [esp+ECh] [ebp-20h] BYREF
  unsigned int column_index; // [esp+108h] [ebp-4h]

  if ( vostok::configs::binary_config_value::value_exists(&config, "Input") )
  {
    v3 = vostok::configs::binary_config_value::operator[](&config, "Input");
    v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)v3);
    v6 = vostok::particle::string_to_evaluate_type((const char *)v5);
    v2 = (vostok::fixed_string<16> *)this;
    this->m_evaluate_type = v6;
  }
  num_rows = 0;
  num_columns = 0;
  row_index = 0;
  column_index = 0;
  vostok::fixed_string<16>::fixed_string<16>(v2, (int)&row_name);
  vostok::fixed_string<16>::fixed_string<16>(v7, (int)&column_name);
  if ( vostok::configs::binary_config_value::value_exists(&config, "source") )
  {
    v8 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&config, "source");
    if ( vostok::configs::binary_config_value::value_exists(v8, "data") )
    {
      v9 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&config, "source");
      rows_config = vostok::configs::binary_config_value::operator[](v9, "data");
      while ( 1 )
      {
        vostok::buffer_string::assignf(&row_name.vostok::buffer_string, "row%d", row_index);
        v11 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v10, (int)&row_name);
        if ( !vostok::configs::binary_config_value::value_exists(
                (vostok::configs::binary_config_value *)rows_config,
                (const char *)v11) )
          break;
        v13 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v12, (int)&row_name);
        row_it = *vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)rows_config,
                    (const char *)v13);
        if ( !vostok::configs::binary_config_value::size(&row_it) )
          break;
        columns_config = &row_it;
        while ( 1 )
        {
          vostok::buffer_string::assignf(&column_name.vostok::buffer_string, "element%d", column_index);
          v15 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                  v14,
                  (int)&column_name);
          if ( !vostok::configs::binary_config_value::value_exists(
                  (vostok::configs::binary_config_value *)columns_config,
                  (const char *)v15) )
            break;
          v17 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                  v16,
                  (int)&column_name);
          column_it = *vostok::configs::binary_config_value::operator[](
                         (vostok::configs::binary_config_value *)columns_config,
                         (const char *)v17);
          if ( !vostok::configs::binary_config_value::size(&column_it) )
            break;
          ++column_index;
        }
        ++row_index;
      }
      num_rows = row_index;
      num_columns = column_index;
      if ( row_index )
      {
        if ( num_columns )
        {
          vostok::particle::color_matrix::reserve(this, num_rows, num_columns);
          for ( row_index = 0; row_index < num_rows; ++row_index )
          {
            vostok::buffer_string::assignf(&row_name.vostok::buffer_string, "row%d", row_index);
            v19 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                    v18,
                    (int)&row_name);
            v41 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            (vostok::configs::binary_config_value *)rows_config,
                                                            (const char *)v19);
            for ( column_index = 0; column_index < num_columns; ++column_index )
            {
              vostok::buffer_string::assignf(&column_name.vostok::buffer_string, "element%d", column_index);
              v21 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                      v20,
                      (int)&column_name);
              element = vostok::configs::binary_config_value::operator[](v41, (const char *)v21);
              point = &this->m_points.pointer[column_index + num_columns * row_index];
              v22 = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)element,
                      "position");
              v24 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v23, (int)v22);
              Wm4::Vector2<float>::operator=((vostok::math::float2 *)v24, &v38);
              v26 = *v25;
              v27 = v25[1];
              v28 = point;
              point->position.x = v26;
              v28->position.y = v27;
              v29 = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)element,
                      (const char *)&stru_9555EC);
              v31 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v30, (int)v29);
              v34 = *(float *)v31;
              v35 = v31[1];
              v36 = v31[2];
              v37 = v31[3];
              v32 = point;
              point->color.x = v34;
              LODWORD(v32->color.y) = v35;
              LODWORD(v32->color.z) = v36;
              LODWORD(v32->color.w) = v37;
            }
          }
        }
      }
    }
  }
}
