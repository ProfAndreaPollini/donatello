#include "pch.h"
#include "../Donatello/src/Donatello.h"
using namespace donatello::events;

TEST(TestCaseName, TestApplication) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
  EXPECT_TRUE(donatello::Application::Get() == nullptr);
  auto a = donatello::Application();
  EXPECT_FALSE(donatello::Application::Get() == nullptr);
  auto const  evt = donatello::EventBus::Get();
  EXPECT_FALSE(evt == nullptr);
KeyEvent const k {};
  evt->Emit(k);
}


