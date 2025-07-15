void __userpurge vostok::render::statistics_float::statistics_float(
        vostok::render::statistics_float *this@<eax>,
        vostok::render::statistics_group *group@<edi>,
        char *name,
        unsigned int decimal_numbers)
{
  vostok::render::statistics_base::statistics_base(this, group, name);
  this->value_num_max_digits = 0;
  this->min_value_num_max_digits = 0;
  this->max_value_num_max_digits = 0;
  this->history_index = 0;
  this->min_max_frame_index = 0;
  this->value = 0.0;
  this->min_value = DOUBLE_1000_0;
  this->max_value = 0.0;
  this->min_value_temp = DOUBLE_1000_0;
  this->max_value_temp = 0.0;
  memset((int)this->history, 0, sizeof(this->history));
  this->m_decimal_numbers = decimal_numbers;
  this->__vftable = (vostok::render::statistics_float_vtbl *)&vostok::render::statistics_float::`vftable';
}
