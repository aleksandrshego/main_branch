import time
from selenium import webdriver
from selenium.webdrivper.common.by import By
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.common.alert import Alert

# Создайте объект опций для браузера Firefox
options = Options()

user_agent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36"
options.set_preference("general.useragent.override", user_agent)
options.add_argument('--headless')

# Запустите браузер с использованием опций
browser = webdriver.Firefox(options=options)
browser.get('https://ct.shipmentlink.com/servlet/TDB1_CargoTracking.do')
time.sleep(2)

xpach = '/html/body/div[4]/center/table[2]/tbody/tr/td/form/div/div[2]/table/tbody/tr[1]/td/table/tbody/tr[1]/td[2]/table/tbody/tr/td/div[1]/input'
browser.find_element(By.XPATH, xpach).send_keys('123124121')

button_xpath = '/html/body/div[4]/center/table[2]/tbody/tr/td/form/div/div[2]/table/tbody/tr[1]/td/table/tbody/tr[1]/td[2]/table/tbody/tr/td/div[2]/input'
browser.find_element(By.XPATH, button_xpath).click()

try:
    alert = Alert(browser)
    print("Alert Text:", alert.text)
    alert.dismiss()  # или alert.accept() в зависимости от вашего случая
except:
    pass

browser.refresh()

xpach = '/html/body/div[4]/center/table[2]/tbody/tr/td/form/div/div[2]/table/tbody/tr[1]/td/table/tbody/tr[1]/td[2]/table/tbody/tr/td/div[1]/input'
browser.find_element(By.XPATH, xpach).send_keys('1231212312')

button_xpath = '/html/body/div[4]/center/table[2]/tbody/tr/td/form/div/div[2]/table/tbody/tr[1]/td/table/tbody/tr[1]/td[2]/table/tbody/tr/td/div[2]/input'
browser.find_element(By.XPATH, button_xpath).click()

try:
    alert = Alert(browser)
    print("Alert Text:", alert.text)
    alert.dismiss()  # или alert.accept() в зависимости от вашего случая
except:
    pass
browser.refresh()


xpach = '/html/body/div[4]/center/table[2]/tbody/tr/td/form/div/div[2]/table/tbody/tr[1]/td/table/tbody/tr[1]/td[2]/table/tbody/tr/td/div[1]/input'
browser.find_element(By.XPATH, xpach).send_keys('121232321')

button_xpath = '/html/body/div[4]/center/table[2]/tbody/tr/td/form/div/div[2]/table/tbody/tr[1]/td/table/tbody/tr[1]/td[2]/table/tbody/tr/td/div[2]/input'
browser.find_element(By.XPATH, button_xpath).click()

try:
    alert = Alert(browser)
    print("Alert Text:", alert.text)
    alert.dismiss()  # или alert.accept() в зависимости от вашего случая
except:
    pass

time.sleep(2)
browser.refresh()
