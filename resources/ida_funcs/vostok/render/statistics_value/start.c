void __thiscall vostok::render::statistics_value<int>::start(vostok::render::statistics_value<int> *this)
{
  int min_value_temp; // edx
  int v3; // eax
  int max_value_temp; // [esp-8h] [ebp-10h]
  int value; // [esp-4h] [ebp-Ch]

  this->history[this->history_index++] = this->value;
  if ( this->history_index == 1 )
    this->history_index = 0;
  if ( this->min_max_frame_index <= 0x20 )
  {
    value = this->value;
    max_value_temp = this->max_value_temp;
    this->min_value_temp = value + (this->min_value_temp < value ? this->min_value_temp - value : 0);
    v3 = vostok::math::max(max_value_temp, value);
  }
  else
  {
    min_value_temp = this->min_value_temp;
    this->max_value = this->max_value_temp;
    v3 = this->value;
    this->min_value = min_value_temp;
    this->min_value_temp = v3;
    this->min_max_frame_index = 0;
  }
  ++this->min_max_frame_index;
  this->value = 0;
  this->max_value_temp = v3;
}


void __thiscall vostok::render::statistics_value<double>::start(vostok::render::statistics_value<double> *this)
{
  double max_value_temp; // xmm0_8
  long double v2; // st7
  double min_value_temp; // xmm0_8

  this->history[this->history_index++] = this->value;
  if ( this->history_index == 1 )
    this->history_index = 0;
  if ( this->min_max_frame_index <= 0x20 )
  {
    min_value_temp = this->min_value_temp;
    if ( this->value <= min_value_temp )
      min_value_temp = this->value;
    this->min_value_temp = min_value_temp;
    max_value_temp = this->max_value_temp;
    if ( max_value_temp <= this->value )
      max_value_temp = this->value;
  }
  else
  {
    max_value_temp = this->value;
    this->min_value = this->min_value_temp;
    this->min_value_temp = max_value_temp;
    v2 = this->max_value_temp;
    this->min_max_frame_index = 0;
    this->max_value = v2;
  }
  ++this->min_max_frame_index;
  this->max_value_temp = max_value_temp;
  this->value = 0.0;
}
