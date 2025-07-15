void __thiscall vostok::render::statistics_value<int>::start(vostok::render::statistics_value<int> *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  this->history[this->history_index++] = this->value;
  if ( this->history_index == 16 )
    this->history_index = 0;
  if ( this->min_max_frame_index <= 0x20 )
  {
    v3 = vostok::render::statistics_value<int>::average(this);
    this->min_value_temp = v3 + (this->min_value_temp < v3 ? this->min_value_temp - v3 : 0);
    v4 = vostok::render::statistics_value<int>::average(this);
    this->max_value_temp -= this->max_value_temp < v4 ? this->max_value_temp - v4 : 0;
  }
  else
  {
    this->min_value = this->min_value_temp;
    this->max_value = this->max_value_temp;
    this->min_value_temp = vostok::render::statistics_value<int>::average(this);
    v2 = vostok::render::statistics_value<int>::average(this);
    this->min_max_frame_index = 0;
    this->max_value_temp = v2;
  }
  ++this->min_max_frame_index;
  this->value = 0;
}


void __usercall vostok::render::statistics_value<double>::start(
        vostok::render::statistics_value<double> *this@<ecx>,
        long double min_value_temp@<xmm0>)
{
  unsigned int *p_history_index; // eax
  vostok::render::statistics_value<double> *history_index; // ecx
  vostok::render::statistics_value<double> *v5; // ecx
  vostok::render::statistics_value<double> *v6; // ecx

  p_history_index = &this->history_index;
  this->history[this->history_index++] = this->value;
  history_index = (vostok::render::statistics_value<double> *)this->history_index;
  if ( history_index == (vostok::render::statistics_value<double> *)16 )
    *p_history_index = 0;
  if ( this->min_max_frame_index <= 0x20 )
  {
    vostok::render::statistics_value<double>::average(history_index, (int)this);
    if ( min_value_temp > this->min_value_temp )
      min_value_temp = this->min_value_temp;
    this->min_value_temp = min_value_temp;
    vostok::render::statistics_value<double>::average(v6, (int)this);
    if ( this->max_value_temp > min_value_temp )
      min_value_temp = this->max_value_temp;
    this->max_value_temp = min_value_temp;
  }
  else
  {
    this->min_value = this->min_value_temp;
    this->max_value = this->max_value_temp;
    vostok::render::statistics_value<double>::average(history_index, (int)this);
    this->min_value_temp = min_value_temp;
    vostok::render::statistics_value<double>::average(v5, (int)this);
    this->min_max_frame_index = 0;
    this->max_value_temp = min_value_temp;
  }
  ++this->min_max_frame_index;
  this->value = 0.0;
}
