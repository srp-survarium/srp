void __thiscall vostok::render::statistics_value<int>::clear(vostok::render::statistics_value<int> *this)
{
  this->history[0] = 0;
  this->history_index = 0;
  this->value = 0;
}
