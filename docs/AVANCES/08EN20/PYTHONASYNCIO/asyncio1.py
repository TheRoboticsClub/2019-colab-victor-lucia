#asyncio-async-await.py

import asyncio
loop = asyncio.get_event_loop()

async def hello():
	await asyncio.sleep(0.05)
	print('Hello!')
	
if __name__ == '__main__':
	loop.run_until_complete(hello())
