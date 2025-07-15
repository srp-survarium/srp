void __thiscall vostok::input::platform::mouse::on_crash(vostok::input::platform::mouse *this)
{
  this->set_exclusive_mode(this, 0);
}
