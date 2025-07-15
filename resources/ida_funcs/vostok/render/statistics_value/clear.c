void __thiscall vostok::render::statistics_value<int>::clear(vostok::render::statistics_value<int> *this)
{
  this->history[0] = 0;
  this->history_index = 0;
  this->value = 0;
}


void __thiscall vostok::render::statistics_value<double>::clear(vostok::render::statistics_value<double> *this)
{
  this->history[0] = 0.0;
  this->history_index = 0;
  this->value = 0.0;
}
