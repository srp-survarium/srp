void __userpurge vostok::render::statistics_value<int>::statistics_value<int>(
        vostok::render::statistics_value<int> *this@<eax>,
        vostok::render::statistics_group *group@<edi>,
        char *name)
{
  vostok::render::statistics_base::statistics_base(this, group, name);
  this->value = 0;
  this->max_value = 0;
  this->value_num_max_digits = 0;
  this->min_value_num_max_digits = 0;
  this->max_value_num_max_digits = 0;
  this->max_value_temp = 0;
  this->history_index = 0;
  this->min_max_frame_index = 0;
  this->__vftable = (vostok::render::statistics_value<int>_vtbl *)&vostok::render::statistics_value<int>::`vftable';
  this->min_value = 1000;
  this->min_value_temp = 1000;
  memset((int)this->history, 0, sizeof(this->history));
}
