void __usercall vostok::render::statistics_value<double>::statistics_value<double>(
        vostok::render::statistics_value<double> *this@<eax>,
        vostok::render::statistics_group *group@<edi>,
        const char *name@<edx>)
{
  vostok::render::statistics_base::statistics_base(this, group, name);
  this->value = 0.0;
  this->max_value = 0.0;
  this->max_value_temp = 0.0;
  this->value_num_max_digits = 0;
  this->min_value_num_max_digits = 0;
  this->max_value_num_max_digits = 0;
  this->history_index = 0;
  this->min_max_frame_index = 0;
  this->__vftable = (vostok::render::statistics_value<double>_vtbl *)&vostok::render::statistics_value<double>::`vftable';
  this->min_value = 1000.0;
  this->min_value_temp = 1000.0;
  this->history[0] = 0.0;
}
