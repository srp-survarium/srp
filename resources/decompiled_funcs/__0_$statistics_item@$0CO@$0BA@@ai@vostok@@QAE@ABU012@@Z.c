void __thiscall vostok::ai::statistics_item<46,16>::statistics_item<46,16>(
        vostok::ai::statistics_item<46,16> *this,
        const vostok::ai::statistics_item<46,16> *__that)
{
  vostok::fixed_string<46> *end; // [esp+3Ch] [ebp-20h] BYREF
  vostok::fixed_string<46> *m_buffer; // [esp+40h] [ebp-1Ch]

  vostok::fixed_string<32>::fixed_string<32>(&this->caption, &__that->caption);
  m_buffer = (vostok::fixed_string<46> *)this->content.m_buffer;
  this->content.m_begin = (vostok::fixed_string<46> *)this->content.m_buffer;
  this->content.m_end = m_buffer;
  end = __that->content.m_end;
  vostok::buffer_vector<vostok::fixed_string<46>>::assign<vostok::fixed_string<46> const *>(
    &this->content,
    __that->content.m_begin,
    (const vostok::fixed_string<46> *const *)&end);
}
