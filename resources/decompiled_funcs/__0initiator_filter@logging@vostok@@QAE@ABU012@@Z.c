void __thiscall vostok::logging::initiator_filter::initiator_filter(
        vostok::logging::initiator_filter *this,
        const vostok::logging::initiator_filter *__that)
{
  this->next = __that->next;
  this->prev = __that->prev;
  this->verbosity = __that->verbosity;
  this->thread_id = __that->thread_id;
  vostok::fixed_string<32>::fixed_string<32>(&this->initiator, &__that->initiator);
}
