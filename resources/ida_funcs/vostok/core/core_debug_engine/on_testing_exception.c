void __thiscall vostok::core::core_debug_engine::on_testing_exception(
        vostok::core::core_debug_engine *this,
        vostok::assert_enum assert_type,
        const char *description,
        _EXCEPTION_POINTERS *exception_information,
        bool is_assertion)
{
  vostok::testing::on_exception(assert_type, description, exception_information, is_assertion);
}
