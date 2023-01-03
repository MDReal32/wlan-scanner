import { getAccessPoints } from "./utils/getAccessPoints";

(async () => {
  // infinite loop on 1 second interval
  while (true) {
    console.log(getAccessPoints().length);
    await new Promise((resolve) => setTimeout(resolve, 1000));
  }
})();
